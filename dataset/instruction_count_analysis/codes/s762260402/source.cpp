//45:00

#include "stdc++.h"

using namespace std;



typedef pair<int, int> Ginkgo;



int main(){

    int N; cin >> N;

    while(N--){

        set<Ginkgo> divs;

        int p, q; cin >> p >> q;

        

        int cnt = 0;

        int l = p*p + q*q;

        for(int m=-200; m<200; m++){

            if(l < m*m) continue;

            for(int n=-200; n<200; n++){

                if(l < m*m + n*n || (n == 0 && m == 0)) continue;

                

                if((m*p+n*q)%(m*m+n*n) == 0 && (m*q-n*p)%(m*m+n*n) == 0)

                    cnt++;

            }

        }

        cout << (cnt == 8? "P": "C") << endl;

    }

}