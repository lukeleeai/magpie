#include<iostream>

#include<algorithm>

#define maxn 100005

#define inf 0x3f3f3f3f

using namespace std;

typedef long int ll;

int main()

{

    string s;

    cin >> s;

    int ls = s.size(), ans = ls;

    for (int i = 1; i < ls; ++i) if (s[i - 1] != s[i]) ans = min(ans, max(i, ls - i));

    cout << ans << endl;

    return 0;

}
