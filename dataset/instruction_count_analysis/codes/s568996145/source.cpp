#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

#define F first

#define S second

#define ALL(a) begin(a), end(a)

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    string s;

    cin >> s;

    bool vis[26] = {};

    for (char c : s)

        vis[c - 'a'] = 1;

    for (int i = 0; i < 26; ++i)

        if (!vis[i]) {

            cout << (char)('a' + i) << '\n';

            return 0;

        }

    cout << "None\n"; 

}
