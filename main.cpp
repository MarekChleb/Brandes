#include <fstream>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <stack>
#include <thread>
#include <utility>
#include <vector>

using namespace std;

vector<double> BC;
vector<vector<int>> neighbour;
unsigned int n;
int current_node;
bool DEBUG = true;

map<int, vector<int>> beg_map;
vector<int> names;
mutex mutex_BC;
mutex mutex_neighbour;

void add_to_beg(int a, int b) {
    if (DEBUG) {
        cout << "Adding to beg " << a << ", " << b << endl;
    }
    auto result_of_insert = beg_map.insert(make_pair(a, vector<int>{b}));
    if (!result_of_insert.second) {
        if (DEBUG) {
            cout << a << " already exists in the map\n";
        }
        result_of_insert.first->second.push_back(b);
    }
    beg_map.insert(make_pair(b, vector<int>()));
}

void read_input(string input) {
    int a, b;
    ifstream file(input);
    if (file.is_open()) {
        while (file >> a >> b)
            add_to_beg(a, b);
        file.close();
    }
    else cout << "Input error" << endl;
    n = beg_map.size();
}

void close_the_gaps() {
    int i = 0;
    neighbour.resize(n);
    names.resize(n);
    BC.resize(n);
    for (auto it = beg_map.begin(); it != beg_map.end(); it++, i++) {
        if (DEBUG) {
            cout << i << ": " << it->first << endl;
        }
        names[i] = (it->first);
        neighbour[i] = (it->second);
        if (DEBUG) {
            for (auto k: it->second) {
                cout << k << " ";
            }
            cout << endl;
        }
    }
    if (DEBUG) {
        for (int j = 0; j < n; j++) {
            cout << j << ": " << names[j] << " and " << neighbour[j].size()
                 << endl;
        }
    }
}

void brandes(int s) {
    stack<int> S;
    queue<int> Q;
    double delta[n], sigma[n], d[n];
    vector<int> P[n];

    for (int w = 0; w < n; w++) {
        P[w] = vector<int>();
        sigma[w] = 0;
        d[w] = -1;
        delta[w] = 0;
    }

    //P.resize(n);
    //P.assign(n, vector<int>());
    //sigma.resize(n);
    //sigma.assign(n, 0);
    //d.resize(n);
    //d.assign(n, -1);
    //delta.resize(n);
    //delta.assign(n , 0);

    Q.push(s);
    sigma[s] = 1;
    d[s] = 0;
    while (!Q.empty()) {
        int v = Q.back();
        Q.pop();
        S.push(v);
        for (int w: neighbour[v]) {
            if (d[w] < 0) {
                Q.push(w);
                d[w] = d[v] + 1;
            }
            if (d[w] == d[v] + 1) {
                sigma[w] += sigma[v];
                P[w].push_back(v);
            }
        }
    }
    while (!S.empty()) {
        int w = S.top();
        S.pop();
        for (int v: P[w]) {
            delta[v] += (sigma[v] / sigma[w]) * (1 + delta[w]);
        }
        if (w != s) {
            lock_guard<mutex> lock(mutex_BC);
            BC[w] += delta[w];
        }
    }
}

void do_brandes_instances() {
    int i;
    bool flague = true;
    while (flague) {
        {
            std::lock_guard<mutex> lock(mutex_neighbour);
            i = current_node;
            if(i < n)
                current_node++;
        }
        if(i > n-1)
            flague = false;
        else
            brandes(i);
    }
}

void perform_brandes(int thread_count) {
    vector<thread> threads;
    for (int i = 0; i < thread_count; i++) {
        threads.push_back(thread(do_brandes_instances));
    }

    for (int i = 0; i < thread_count; i++) {
        threads[i].join();
    }
}

void print_output_into_file(string output_file) {
    ofstream file(output_file);
    if (file.is_open()) {
        for(int i = 0; i < n; i++) {
            if(neighbour[i].size() > 0)
                file << names[i] << " " << BC[i] << endl;
        }
        file.close();
    }
    else cout << "Output error" << endl;
}

int main(int argc, char *argv[]) {
    int thread_count = atoi(argv[1]);
    string input = argv[2];
    string output = argv[3];

    read_input(input);
    close_the_gaps();
    perform_brandes(thread_count);
    print_output_into_file(output);

    return 0;
}