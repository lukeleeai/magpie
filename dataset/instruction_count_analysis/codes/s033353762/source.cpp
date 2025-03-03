#include <iostream>

#include <string.h>

using namespace std;



int main() {

    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    string s;

    cin >> s;

    if (n % 2 == 1) {

        cout << "No"<<endl;

    } else {

        string s1 = s.substr(0, n / 2);

        string s2 = s.substr(n / 2, n / 2);

        if (s1 == s2) {

            cout << "Yes"<<endl;

        } else {

            cout << "No"<<endl;

        }

    }

    return 0;

}
