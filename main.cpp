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

vector<double> BC, sigma, delta;
vector<int> V, d;
vector<vector<int>> P, neighbour;
int n;

map<int, vector<int>> beg_map;
map<int, int> dict;

void add_to_beg(int a, int b) {
    auto result_of_insert = beg_map.insert(make_pair(a, vector<int>{b}));
    if (!result_of_insert.second) {
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
    else cout << "File error" << endl;
    n = beg_map.size();
}

int main(int argc, char *argv[]) {

    /**
     * TODO reserve:
     * BC 0
     * P list()
     * sigma 0
     * d -1
     * delta 0
     */

    for (int v: V) {
        BC[v] = 0;
    }

    for (int s: V) { //TODO parallel
        vector<int> S = {}; //stack
        sigma[s] = 1;
        d[s] = 0;
        vector<int> Q; //FIFO, queue, reverse kolejność, ew TODO change on
        // queue
        Q.insert(Q.begin(), s);
        while (!Q.empty()) {
            int v = Q.back();
            Q.pop_back();
            S.push_back(s);
            for (int w: neighbour[v]) {
                if (d[w] < 0) {
                    Q.insert(Q.begin(), w);
                    d[w] = d[v] + 1;
                }
                if (d[w] == d[v] + 1) {
                    sigma[w] += sigma[v];
                    P[w].push_back(v);
                }
            }
        }
        while (!S.empty()) {
            int w = S.back();
            S.pop_back();
            for (int v: P[w]) {
                delta[v] += (sigma[v] / sigma[w]) * (1 + delta[w]);
            }
            if (w != s) {
                BC[w] += delta[w];
            }
        }
    }

    return 0;
}