#include <iostream>

#include <cstdio>

#include <algorithm>

#include <vector>

#include <queue>

#include <set>

#include <map>

using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < n; i++)

const int mo = 1e9 + 7;

int grid[3][3];

void solve()

{

    int c[3][3];

    rep(i,3)rep(j,3)cin>>c[i][j];

    int a[3],b[3];

    for(a[0]=0;a[0]<=100;a[0]++)

    {

        for(a[1]=0;a[1]<=100;a[1]++)

        {

            for(a[2]=0;a[2]<=100;a[2]++)

            {

                b[0]=c[0][0]-a[0];

                b[1]=c[0][1]-a[0];

                b[2]=c[0][2]-a[0];

                

                bool ok=1;

                rep(i,3)

                {

                    rep(j,3)

                    {

                        ok&=c[i][j]==a[i]+b[j];

                    }

                }

                if(ok)

                {

                    cout<<"Yes"<<endl;

                    return ;

                }

            }

        }

    }

    cout<<"No"<<endl;

}

main()

{

    cin.tie(0);

    ios::sync_with_stdio(0);

    solve();

    return 0;

}