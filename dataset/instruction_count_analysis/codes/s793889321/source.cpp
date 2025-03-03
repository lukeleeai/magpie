#include "stdc++.h"

using namespace std;



typedef pair<int, int> Ginkgo;



map<int, int> sq;



int main(){

    for(int i=0; i<200; i++)

        sq[i*i] = i;

    

    int N; cin >> N;

    while(N--){

        set<Ginkgo> divs;

        int p, q; cin >> p >> q;

        for(int i=1; i<=p*p + q*q; i++){

            for(int m=-200; m<200; m++) if(i - m*m >= 0){

                int n2 = i - m*m;

                if(sq.count(n2) == 0) continue;

                

                for(auto n: {-sq[n2], sq[n2]}){

                    if((m*p+n*q)%i == 0 && (m*q-n*p)%i == 0){

                        divs.insert({n, m});

                    }

                }

            }

        }

        cout << (divs.size() == 8? "P": "C") << endl;

    }

}