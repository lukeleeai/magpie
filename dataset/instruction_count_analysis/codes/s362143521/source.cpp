#include "stdc++.h"

using namespace std;



int main()

{

    int H, W, CH, CW, DH, DW;

    cin >> H >> W >> CH >> CW >> DH >> DW;

    --CH;

    --CW;

    --DH;

    --DW;



    vector<string> S(H);

    for (int i=0;i<H;++i) { cin >> S[i]; }



    vector<int> Cost(H * W, 1000001);

    deque< pair<int, int> > Q;



    const auto insert = [&](int x, int y, int cost, int extraCost)

    {

        if (x < 0 || W <= x || y < 0 || H <= y) { return; }

        if (S[y][x] == '#') { return; }



        const auto newCost = cost + extraCost;

        if (Cost[x + y * W] <= newCost) { return; }

        Cost[x + y * W] = newCost;



        if (extraCost == 0) { Q.emplace_front(x, y); }

        else                { Q.emplace_back(x, y); }

    };



    insert(CW, CH, 0, 0);



    int ans = -1;



    while (!Q.empty())

    {

        const auto x = Q.front().first;

        const auto y = Q.front().second;

        Q.pop_front();



        const auto cost = Cost[x + y * W];

        if (x == DW && y == DH) { ans = cost; break; }



        insert(x - 1, y, cost, 0);

        insert(x + 1, y, cost, 0);

        insert(x, y - 1, cost, 0);

        insert(x, y + 1, cost, 0);



        for (int dx=-2;dx<=2;++dx)

        for (int dy=-2;dy<=2;++dy)

        {

            insert(x + dx, y + dy, cost, 1);

        }

    }



    cout << ans << endl;

}