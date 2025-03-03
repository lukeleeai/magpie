#include "stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){

    string s;

    cin >> s;

    vector<string> e={"", "A"};

    for (auto a:e){

        for (auto b:e){ 

            for (auto c:e){ 

                for (auto d:e)  {

                    if (s == a + "KIH" + b + "B" + c + "R" + d) {

                    cout << "YES" <<endl;

                    return 0;

                    } 

                }

            }

        }

    }

    cout << "NO" <<endl;

    return 0;

}