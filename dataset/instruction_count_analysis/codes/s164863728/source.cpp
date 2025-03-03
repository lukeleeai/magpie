#include <iostream>

using namespace std;

int main() {

    string s;

    cin >> s;

    int slen=s.length(), len=0;

    int l=0;

    for(int i=0;i<slen;i++) {

        char c = s[i];

        if (c=='A' || c=='C' || c=='G' || c=='T') {

            l++;

            if (l>len) len = l;

        } else {

            l = 0;

        }

    }

    cout << len << endl;

    return 0;

}