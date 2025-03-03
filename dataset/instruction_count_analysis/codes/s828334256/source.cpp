#include "stdc++.h"



using namespace std;



int main() {

    string s;

    cin >> s;

    int cnt[26] = {0};

    for (int i = 0; i < s.size(); i++) {

        cnt[s[i] - 'a']++;

    }

    for (int i = 0; i < 26; i++) {

        if (cnt[i] & 1) {

            puts("No");

            return 0;

        }

    }

    puts("Yes");

    return 0;

}
