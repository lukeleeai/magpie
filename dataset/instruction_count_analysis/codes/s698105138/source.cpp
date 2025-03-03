#include"stdc++.h"

using namespace std;

const int maxn = 1e5+1;

pair<int,int> s[maxn];

int n;

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for(int i = 0;i < n;++i)cin >> s[i].first >> s[i].second, ++s[i].second;

    sort(s, s+n);

    int l = 0, r = 1000000001, w = 0;

    for(int i = 0;i < n;++i){

        l = max(l, s[i].first);

        r = min(r, s[i].second);

        w = max(w, s[i].second-s[i].first);

    }

    int res = w+max(0, r-l);

    int su = s[n-1].second;

    for(int i = n-2;i > -1;--i)res = max(res, max(0, r-s[i].first) + max(0, su-l)), su = min(su, s[i].second);

    cout << res << '\n';

}
