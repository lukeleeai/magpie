#include <iostream>

#include <string>

#include <stdio.h>



using namespace std;



int main() {

    string s, t;

    while (cin >> s >> t) {

        int len = s.size(), i;

        for (i = 0; i < len; ++i) {

            if (s.find(s[i]) != t.find(t[i])) break;

        }

        if(i < len) puts("No");

        else puts("Yes");

    }

    return 0;

}
