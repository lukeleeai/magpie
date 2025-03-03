#include "stdc++.h"

using namespace std;



typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)

#define all(x) (x).begin(),(x).end()

#define pb push_back

#define fi first

#define se second



typedef vector<int> vi;



vi normarize(const vi &v)

{

    vector<vi> r;

    rep(i,4)

    {

        vi t;

        rep(j,4) t.pb(v[(i+j)%4]);

        r.pb(t);

    }

    sort(all(r));

    return r[0];

}



inline ll P(int n, int r)

{

    if(n<r) return 0;



    ll ret=1;

    rep(i,r) ret*=n-i;

    return ret;

}



inline ll POW(int x, int n)

{

    ll ret=1;

    rep(i,n) ret*=x;

    return ret;

}



inline ll DIM(const vi &v)

{

    if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3]) return 4;

    else if(v[0]==v[2] && v[1]==v[3]) return 2;

    return 1;

}



int main()

{

    int n;

    scanf(" %d", &n);



    vector<vi> c(n,vi(4));

    rep(i,n)rep(j,4) scanf(" %d", &c[i][j]);



    map<vi,int> ct;

    rep(i,n)

    {

        c[i]=normarize(c[i]);

        if(ct.find(c[i])==ct.end()) ct[c[i]]=1;

        else ++ct[c[i]];

    }



    ll ans=0;

    // 上面i, 下面j

    rep(i,n)rep(j,i)

    {

        // 下面の向きを設定

        rep(k,4)

        {

            vi u;

            rep(x,4) u.pb(c[j][(k+x)%4]);

            swap(u[1],u[3]);



            vector<vi> sides(4);

            map<vi,int> sides_ct;

            rep(x,4)

            {

                vi t(4);

                t[0]=c[i][(x+1)%4];

                t[1]=c[i][x];

                t[2]=u[x];

                t[3]=u[(x+1)%4];

                t=normarize(t);



                sides[x]=t;

                if(sides_ct.find(t)==sides_ct.end()) sides_ct[t]=1;

                else ++sides_ct[t];

            }



            ll add=1;

            for(const auto &x:sides_ct)

            {

                vi key=x.fi;

                int value=x.se;



                // 使ってないタイルのうち当てはめられる個数

                int num=ct[key];

                if(c[i]==key) --num;

                if(c[j]==key) --num;



                // 選び方、向き、位置

                add*=P(num,value)*POW(DIM(key),value);

            }

            ans+=add;

        }

    }



    // 向かい合う面の個数ぶん重複する

    cout << ans/3 << endl;

    return 0;

}
