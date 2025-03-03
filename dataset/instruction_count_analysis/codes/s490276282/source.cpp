#include "stdc++.h"

using namespace std;

int main()

{

    string s;

    cin >> s;

    int c = s.find("C"); 

    int f = s.find("F", c);

    if(c >= s.length() || f >= s.length() || c > f)

        cout << "No" << endl;

    else

        cout << "Yes" << endl;

    return 0;

}