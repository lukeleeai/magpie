#include "stdc++.h"

using namespace std;



int main() {

    string s;

    cin >> s;

    int a = 0, z = 0;

    for(int i = 0; i < s.size(); i++) {

        if (s[i] == 'A') {

            a = i;

            break;

        }

    }

    for(int i = 0; i < s.size(); i++) {

        if (s[i] == 'Z') {

            z = i;

        }

    }

    string res = "";

    for(int i = a; i <= z; i++) {

        res += s[i];

    }

    cout << res.size() << endl;

    return 0;

}