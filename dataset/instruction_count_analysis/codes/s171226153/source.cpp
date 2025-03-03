#include"stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

typedef long long ll;

#define orderd_set tree<pair<int, int>, null_type,greater<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

//find_by_order(k)

//order_of_key(k)

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e3+69;

#define ALL(x) begin(x),end(x)

#define sz(x) (ll)x.size()

const int OO = 0x3f3f3f3f;

const int mod = 1000000007;



int n, m, k,xs, ys ,xt ,yt;

string grid[N];

vector<vector<ll>>dis;

int mvx[] = {1, -1, 0, 0};

int mvy[] = {0, 0, 1, -1};







bool valid(int x, int y)

{

    return x < n && x >= 0 && y < m && y >= 0 && grid[x][y] == '.';

}





void bfs(int sx, int sy)

{

    queue<pair<int, int>> q;

    q.push({sx, sy});

    dis[sx][sy] = 0;

    while(sz(q))

    {

        int ux = q.front().first;

        int uy = q.front().second;

        q.pop();

        if(ux == xt && uy == yt)

            return;

        for(int i = 0; i< 4; i++)

        {

            for(int j = 1; j<= k; j++)

            {

                int vx = ux + mvx[i]*j;

                int vy = uy + mvy[i]*j;

                if(valid(vx, vy))

                {

                    if(dis[vx][vy] == OO)

                    {

                        dis[vx][vy] = dis[ux][uy]+1;

                        q.push({vx, vy});

                    }

                    else if(dis[vx][vy] >= dis[ux][uy]+1)

                    {

                        dis[vx][vy] = dis[ux][uy]+1;

                    }

                    else

                        break;

                }

                else

                    break;

            }

        }

    }

}







int main()

{

    FIO

    cin >> n >> m >> k >> xs >> ys >> xt >> yt;

    dis=vector<vector<ll>>(n+69,vector<ll>(m+69,OO));

    for(int i = 0; i< n; i++)

    {

        cin >> grid[i];

    }

    xs--;xt--;yt--;ys--;

    bfs(xs, ys);

//    for(int i = 0; i< n; i++)

//    {

//        for(int j = 0; j< m; j++)

//        {

//            cout << dis[i][j] << "          ";

//        }

//        cout << "\n";

//    }

    if(dis[xt][yt] == OO)

        cout << -1 << "\n";

    else

        cout << dis[xt][yt] << "\n";

    return 0;

}
