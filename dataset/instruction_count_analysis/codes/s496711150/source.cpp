#include<iostream>

#include<string>

#include<algorithm>

#include<list>

#include<set>

#include<map>

#include<queue>

#include<stack>

#include<numeric>

#include<vector>

#include<cstdio>

#include<climits>

#include<cfloat>

#include<cstring>

#define foreach(t,p,tit) for(t::iterator tit=p.begin();tit!=p.end();++tit)

#define rforeach(t,p) for(t::reverse_iterator it=p.rbegin();it!=p.rend();++it)

#define all(p) p.begin(),p.end()

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int costs[1010][1010];

int times[1010][1010];

int d[1010];

#define INF 10000

struct E

{

    int a,b,c;

    E(){};

    E(int a,int b,int c):a(a),b(b),c(c){};

};

#define MONEY 0

#define EKI 1



int main()

{

    int n,m;

    while(cin>>n>>m)

    {

        if(n==0&&m==0)break;

        memset(costs,INF,sizeof(costs));

        memset(times,INF,sizeof(times));

        vector<E> cs;

        vector<E> ts;

        int a,b,c,t;

        rep(i,n)

        {

            cin>>a>>b>>c>>t;

            costs[a][b] = c; costs[b][a] = c;

            times[a][b] = t; times[b][a] = t;

            cs.push_back(E(a,b,c));

            cs.push_back(E(b,a,c));

            ts.push_back(E(a,b,t));

            ts.push_back(E(b,a,t));

        }

        rep(i,m)

        {

            costs[i][i] = 0;

            times[i][i] = 0;

        }

        int k,p,q,r;

        cin>>k;

        rep(i,k)

        {

            memset(d,INF,sizeof(d));

            cin >> p >> q >> r;

            d[p] = 0;

            if(r==MONEY)

            {

                //rep(j,n*2){if(cs[j].a == p) d[cs[j].b] = cs[j].c;}

                while(true)

                {

                    bool update = false;

                    rep(j,n*2)

                    {

                        //cout <<"edge"<< j<<cs[j].a<<"to"<<cs[j].b << endl;



                        if( (d[ cs[j].a] != INF) && d[cs[j].b] > d[cs[j].a] + cs[j].c)

                        {

                            d[cs[j].b] = d[ cs[j].a] + cs[j].c;

                            update = true;

                            //cout << "updated" <<d[cs[j].b] <<endl;

                        }

                    }

                    if(!update)break;

                }

                cout << d[q]<<endl;

            }

            else

            {

                //rep(j,n*2){if(ts[j].a == p) d[ts[j].b] = ts[j].c;}

                while(true)

                {

                    bool update = false;

                    rep(j,n*2)

                    {

                        if(d[ ts[j].a] != INF && d[ts[j].b] > d[ts[j].a] + ts[j].c)

                        {

                            d[ts[j].b] = d[ ts[j].a] + ts[j].c;

                            update = true;

                        }

                    }

                    if(!update)break;

                }

                cout << d[q]<<endl;

            }

        }

    }



    return 0;

}