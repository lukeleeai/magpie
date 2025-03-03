#include"stdc++.h"

using namespace std;

#define LL long long

#define MAX 0X3f3f3f3f

#define maxn 200000+10

int vis[200006];

map<int,int>mmp;

int main()

{

    int n,m;

    cin>>n>>m;

    //1-n是否路径只有2

    string s2="IMPOSSIBLE";

    for(int i=1;i<=m;i++)

    {

        int a,b;

        cin>>a>>b;

        if(a==1)

        {

            if(vis[b])

            {

                s2="POSSIBLE";

            }

            vis[b]=1;

        }

        if(b==n)

        {

            if(vis[a])

            {

                s2="POSSIBLE";

            }

            vis[a]=1;

        }

    }

    cout<<s2<<endl;

    for(int i=1;i<=n;i++)

    {



    }

}
