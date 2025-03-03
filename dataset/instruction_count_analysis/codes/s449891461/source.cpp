#include "stdc++.h"

using namespace std;



#define REP(i,p,n) for(ll i=p;i<ll(n);++i)

#define rep(i,n) REP(i,0,n)



using ll = long long;

using pll = pair<ll, ll>;



const ll MAXN = 1002;

ll C[MAXN][MAXN];



int main()

{

    ll H, W;

    cin >> H >> W;



    ll CH, CW, DH, DW;

    cin >> CH >> CW >> DH >> DW;

    --CH;

    --CW;

    --DH;

    --DW;



    vector<string> S(H);

    rep (i, H) { cin >> S[i]; }



    rep (x, MAXN) rep (y, MAXN) { C[x][y] = MAXN * MAXN; }



    using Node = tuple<ll, ll, ll>;

    priority_queue<Node, vector<Node>, greater<Node> > Q;



    const auto insert = [&](ll xx, ll yy, ll newCost)

    {

        if (xx < 0 || W <= xx) { return; }

        if (yy < 0 || H <= yy) { return; }

        if (S[yy][xx] == '#') { return; }

        if (C[yy][xx] <= newCost) { return; }



        C[yy][xx] = newCost;

        Q.emplace(newCost, xx, yy);

    };



    insert(CW, CH, 0);



    ll ans = -1;



    while (!Q.empty())

    {

        const auto node = Q.top();

        Q.pop();



        const auto cost = get<0>(node);

        const auto cx = get<1>(node);

        const auto cy = get<2>(node);



        if (cx == DW && cy == DH) { ans = cost; break; }



        insert(cx - 1, cy, cost);

        insert(cx + 1, cy, cost);

        insert(cx, cy - 1, cost);

        insert(cx, cy + 1, cost);



        for (ll dx=-2;dx<=2;++dx)

        for (ll dy=-2;dy<=2;++dy)

        {

            insert(cx + dx, cy + dy, cost + 1);

        }

    }

    cout << ans << endl;



    return 0;

}
