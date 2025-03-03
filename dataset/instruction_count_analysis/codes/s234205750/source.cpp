#include <cctype>

#include <cstdio>

#include <algorithm>

#include <vector>

using namespace std;

typedef long long int64;

inline int read(int f = 1, int x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x; 

}

const int N = 131072+5;

int n, w[N], ch[2][N], c[N];

int64 d[N], l = 1e10, r = 0, mid, ans, pre[N], dfn[N];

vector<pair<int64, int64> > f[N];

inline bool cmpx(pair<int64, int64> a, pair<int64, int64> b) { return a.first < b.first; }

inline bool cmpy(pair<int64, int64> a, pair<int64, int64> b) { return a.second < b.second; }

void insert(vector<pair<int64, int64> > &ls, vector<pair<int64, int64> > &rs, vector<pair<int64, int64> > &s)

{

    int sy = ls.size(), sz = rs.size();

    if(sy > sz) swap(sy, sz), swap(ls, rs);

    sort(ls.begin(), ls.end(), cmpy);

    sort(rs.begin(), rs.end(), cmpx);

    pre[0] = rs[0].second;

    for(int i = 1; i < sz; ++i) pre[i] = min(pre[i-1], rs[i].second);

    for(int i = 0, j = sz-1; i < sy; ++i)

    {

        while(j >= 0&&ls[i].second+rs[j].first > mid) --j;

        if(j >= 0) s.push_back(make_pair(ls[i].first, pre[j]));

    }

    sort(ls.begin(), ls.end(), cmpx);

    sort(rs.begin(), rs.end(), cmpy);

    pre[0] = rs[0].first;

    for(int i = 1; i < sz; ++i) pre[i] = min(pre[i-1], rs[i].first);

    for(int i = 0, j = sz-1; i < sy; ++i)

    {

        while(j >= 0&&ls[i].first+rs[j].second > mid) --j;

        if(j >= 0) s.push_back(make_pair(pre[j], ls[i].second));

    }

}

bool valid()

{

    for(int i = n; i; --i)

    {

        int x = dfn[i]; if(f[x].size()) f[x].clear();

        if(!c[x]) f[x].push_back(make_pair(d[x], d[x]));

        else

        {

            int y = ch[0][x], z = ch[1][x];

            mid += d[x]<<1;

            insert(f[y], f[z], f[x]);

            mid -= d[x]<<1; f[y].clear(), f[z].clear();

        }       

        if(f[x].empty()) return false; 

    }

    return true;

}

void dfs(int x)

{

    d[x] += w[x], dfn[++n] = x;

    if(!c[x]) return l = min(l, d[x]), void(r = max(r, d[x]<<1));

    d[ch[0][x]] = d[ch[1][x]] = d[x];

    dfs(ch[0][x]), dfs(ch[1][x]);

}

int main()

{

    n = read(); 

    for(int i = 2; i <= n; ++i)

    {

        int x = read(); w[i] = read();

        ch[c[x]++][x] = i;

    }

    n = 0, dfs(1);

    while(l <= r)

    {

        mid = (l+r)>>1;

        if(valid()) ans = mid, r = mid-1;

        else l = mid+1;

    }

    printf("%lld\n", ans);

    return 0;

}