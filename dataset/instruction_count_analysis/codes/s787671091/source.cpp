#include "stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){

    string s;

    cin >> s;

    if(s=="AKIHABARA"){

        cout << "YES" << endl;

        return 0;

    }

    string t = s;

    int n=t.size();

    rep(i,n+1){

        t.insert(t.begin()+i,'A');

        if(t=="AKIHABARA"){

            cout << "YES" << endl;

            return 0;

        }

        rep(j,n+2){

            string u = t;

            u.insert(u.begin()+j,'A');

            if(u=="AKIHABARA"){

                cout << "YES" << endl;

                return 0;

            }

            rep(k,n+3){

                string v = u;

                v.insert(v.begin()+k,'A');

                if(v=="AKIHABARA"){

                    cout << "YES" << endl;

                    return 0;

                }

                rep(l,n+4){

                    string w = v;

                    w.insert(w.begin()+l,'A');

                    if(w=="AKIHABARA"){

                        cout << "YES" << endl;

                        return 0;

                    }

                    w = v;

                }

                v = u;

            }

            u = t;

        }

        t = s;

    }

    cout << "NO" << endl;

 }