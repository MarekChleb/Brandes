#include <iostream>
#include <vector>

using namespace std;

int main() {
    /**
     * for each v : V
     *  BC[v] = 0;
     */
    vector<double> BC, sigma, delta;
    vector<int> V, d;
    vector<vector<int>> P;


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
        vector<int> Q; //FIFO, queue, reverse kolejność
        Q.push_back(s);
        while (!Q.empty()) {
            int v = Q.
        }
    }
    /**
     *


   sigma[s] = 1;

   d[s] = 0;

   Q = queue(); // FIFO

   Q.push_back(s);

   while (!Q.empty()) {

      v = Q.pop_front();

      S.push(v);

      for each neighbor w of v {

         if d[w] < 0 {

            Q.push_back(w);

            d[w] = d[v] + 1;

         }

         if (d[w] == d[v] + 1) {

            sigma[w] += sigma[v];

            P[w].append(v);

         }

      }

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