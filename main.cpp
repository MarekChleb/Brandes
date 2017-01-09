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

int main(int argc, char *argv[]) {
    /**
     * for each v : V
     *  BC[v] = 0;
     */



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
    /**
     *
   }
   while (!S.empty()) {
     w = S.pop();
     for each v in P[w]
        delta[v] += (sigma[v] / sigma[w])(1 + delta[w]);
     if (w != s)

        BC[w] += delta[w];

   }

}

     */
    return 0;
}