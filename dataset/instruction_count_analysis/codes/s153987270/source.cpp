#include "stdc++.h"

using namespace std;

int main(){



    int n;

    cin >> n;



    string s;

    cin >> s;



    for(int i=0;i<s.length();i++){

        s[i] = (s[i] - 'A' + n) % 26 + 'A';

    }



    cout << s << endl;

    return 0;

}
