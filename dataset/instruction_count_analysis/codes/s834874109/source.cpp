#include <iostream>

#include <set>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)



int main(){

    int N;cin >> N;

    set<string> se;

    rep(i,N){

        string s;cin >> s;

        se.insert(s);

    }

    cout << se.size() << endl;

    return 0;

}