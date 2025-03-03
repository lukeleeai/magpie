///Bismillahir Rahmanir Rahim

#include "bits/stdc++.h"

 

#pragma GCC optimize("Ofast")

#pragma GCC optimize ("unroll-loops")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

 

#pragma warning(disable:4786)

#pragma warning(disable:4996)

 

#define                           ll                          long long

#define                           fi                          first

#define                           si                          second

#define                           mp                          make_pair

#define                           pb                          push_back

#define                           pi                          pair<ll,ll>

#define                           clr(x)                      memset(x,0,sizeof(x));

#define                           f(i,l,r)                    for(int i=l;i<=r;i++)

#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)

#define                           done(i)                     cout<<"done = "<<i<<endl;

#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;

#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

 

using namespace std;

 

const ll inf=1e18;

const int mod=1e9+7;

const int M=100005;

 

 main()

 

{

 

    int h,w,k;

    scanf("%d%d%d",&h,&w,&k);

    string s[h+2];

    int dis[h+2][w+2];

    set<pi>row[h+2],col[w+2];

    char tmp[w+2];

    memset(dis,-1,sizeof dis);

    int sx,sy,ex,ey;

    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);

    sx--;sy--;ex--;ey--;

    f(i,0,h-1)

    {

        scanf("%s",tmp);

        s[i]=tmp;

    }

    f(i,0,h-1)

    {

        f(j,0,w-1)

        {

            if(s[i][j]=='@')row[i].insert(pi(j,1));

           else row[i].insert(pi(j,0));

        }

    }

    f(j,0,w-1)

    {

        f(i,0,h-1)

        {

            if(s[i][j]=='@')col[j].insert(pi(i,1));

            else col[j].insert(pi(i,0));

        }

    }

    queue<pi>q;

    set<pi>::iterator it;

    q.push(mp(ex,ey));

    dis[ex][ey]=0;

    row[ex].erase(mp(ey,0));

    col[ey].erase(mp(ex,0));

    while(!q.empty())

    {

        int x=q.front().fi;

        int y=q.front().si;

        //cout<<x<<" "<<y<<" "<<dis[x][y]<<endl;

        int z;

        q.pop();

        vector<pi>nw;

 

        //dan

        it=row[x].upper_bound(mp(y,-12));

        while(it!=row[x].end())

        {

            pi zz=*it;

            if(abs(zz.fi-y)>k)break;

            if(zz.si==1)break;

            else

            {

                int nx=x;

                int ny=zz.fi;

                if(dis[nx][ny]==-1){

                dis[nx][ny]=1+dis[x][y];

                nw.pb(zz);

                q.push(mp(nx,ny));

                }

            }

            it++;

        }

        for(auto p:nw)row[x].erase(p);

        nw.clear();

        //bam

 

        it=row[x].upper_bound(mp(y,-12));

        if(it!=row[x].begin()){

                it--;

        while(1)

        {

            pi zz=*it;

           // cout<<zz.fi<<"###"<<abs(zz.si-y)<<" "<<y<<endl;

            if(abs(zz.fi-y)>k)break;

            if(zz.si==1)break;

            else

            {

                int nx=x;

                int ny=zz.fi;

                if(dis[nx][ny]==-1){

                dis[nx][ny]=1+dis[x][y];

                nw.pb(zz);

                q.push(mp(nx,ny));

                }

            }

            if(it==row[x].begin())break;

            else it--;

 

 

        }

 

        for(auto p:nw)row[x].erase(p);

        nw.clear();

        }

 

        //niche

 

        it=col[y].upper_bound(mp(x,-12));

        while(it!=col[y].end())

        {

            pi zz=*it;

            if(abs(zz.fi-x)>k)break;

            if(zz.si==1)break;

            else

            {

                int nx=zz.fi;

                int ny=y;

                if(dis[nx][ny]==-1){

                dis[nx][ny]=1+dis[x][y];

                nw.pb(zz);

                q.push(mp(nx,ny));

                }

            }

            it++;

 

        }

         for(auto p:nw)col[y].erase(p);

        nw.clear();

        // upore

 

 

        it=col[y].upper_bound(mp(x,-12));

        if(it!=col[y].begin()){

                it--;

        while(1)

        {

            pi zz=*it;

            if(abs(zz.fi-x)>k)break;

            if(zz.si==1)break;

            else

            {

                int nx=zz.fi;

                int ny=y;

                if(dis[nx][ny]==-1){

                dis[nx][ny]=1+dis[x][y];

                nw.pb(zz);

                q.push(mp(nx,ny));}

            }

            if(it==col[y].begin())break;

            else it--;

 

 

        }

         for(auto p:nw)col[y].erase(p);

         nw.clear();

        }

 

    }

    printf("%d\n",dis[sx][sy]);

    return 0;

 

}

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 