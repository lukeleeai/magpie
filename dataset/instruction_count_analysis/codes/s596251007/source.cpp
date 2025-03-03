#include"stdc++.h"

using namespace std;

string s;

int main(){

    ios::sync_with_stdio(false);

    cin >> s;

    for(int i = 0; i < (int)s.size(); i += 2){

        cout << s[i];

    }

    return 0;

}