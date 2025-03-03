#include "stdc++.h"



using namespace std;



const int N = 1e5 + 5;

int nxt[26][N];



int main() {

    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);



    string s , t;

    cin >> s >> t;



    for (char &c : s) c -= 'a';

    for (char &c : t) c -= 'a';



    memset(nxt , -1 , sizeof nxt);

    for (int i = s.size() - 1 ;i >= 0 ;i--) {

        for (int j = 0 ;j < 26 ;j++)

            nxt[j][i] = nxt[j][i + 1];

        nxt[s[i]][i] = i;

    }



    for (char &c : t) {

        if (nxt[c][0] == -1) {

            cout << -1;

            return 0;

        }

    }



    int p = s.size() - 1;

    long long len = 0;

    for (char &c : t) {

        if (nxt[c][p + 1] != -1) {

            len += nxt[c][p + 1] - p;

            p = nxt[c][p + 1];

        } else {

            len += s.size() - p - 1;

            p = nxt[c][0];

            len += p + 1;

        }

    }



    cout << len;

}