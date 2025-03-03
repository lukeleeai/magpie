#include "stdc++.h"

using namespace std;

const long long N = 1e6+5 , M = 998244353, OO = 0x3f3f3f3f;

typedef long long ll;

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const double Pii = 3.14159265359;

int n, m, mxk, X1, Y1, X2, Y2;

bool grid[N];

int dis[N];

char ch;

int cr[] = {-1, 1, 0, 0};

int cc[] = {0, 0, -1, 1};



bool valid(int nr, int nc)

{

    return (nr >= 0 && nr < n && nc >= 0 && nc < m);

}



void BFS1(int X1, int Y1)

{

    memset(dis, OO, sizeof dis);

    dis[X1*m+Y1] = 0;

    queue<pair<int, int>> q;

    q.push({X1, Y1});

    while(!q.empty())

    {

        pair<int, int> pu = q.front();

        q.pop();

        for(int k=0; k<4; ++k)

        {

            int kused = 0;

            bool ok = 1;

            int nr = pu.first;

            int nc = pu.second;

            while(kused < mxk && ok)

            {

                nr += cr[k];

                nc += cc[k];

                if(valid(nr, nc) && grid[nr*m+nc] && dis[nr*m+nc] >= dis[pu.first*m+pu.second]+1)

                {

                    if(dis[nr*m+nc] > dis[pu.first*m+pu.second] + 1)

                    {

                        q.push({nr, nc});

                        dis[nr*m+nc] = dis[pu.first*m+pu.second] + 1;

                    }

                    kused++;

                }

                else ok = 0;

            }

        }

    }

}







int main()

{

    FIO

    cin >> n >> m >> mxk >> X1 >> Y1 >> X2 >> Y2;

    X1--; Y1--; X2--; Y2--;

    for(int i=0; i<n; ++i)

    {

        for(int j=0; j<m; ++j)

        {

            cin >> ch;

            if(ch == '.') grid[i*m+j] = 1;

            else grid[i*m+j] = 0;

        }

    }

    BFS1(X1, Y1);

    /*

    for(int i=0; i<n; ++i)

    {

        for(int j=0; j<m; ++j) cout << dis[i*m+j] << " ";

        cout << endl;

    }

    */



    if(dis[X2*m+Y2] == OO) cout << -1 << endl;

    else cout << dis[X2*m+Y2] << endl;

    return 0;

}
