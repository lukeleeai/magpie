#include<iostream>

#include<cstring>

#include<vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)

#define INF 300000



struct E

{

    int a,b,c,t;

    E(){};

    E(int a,int b,int c,int t):a(a),b(b),c(c),t(t){};

};

//E cs[700];

unsigned int d[150];



int main()

{

    int n,m,k,p,q,r;

    while(cin >> n >> m)

    {

        if(n==0 && m==0)break;

        vector<E> cs;   

        int ta,tb,tc,tt;

        rep(i,n)

        {

            cin >> ta>>tb>>tc >>tt;

            cs.push_back( E(ta,tb,tc,tt));

            cs.push_back( E(tb,ta,tc,tt));

        }



        cin >> k;

        rep(i,k)

        {

            memset(d,INF,150*sizeof(int));

            cin >> p >> q >>r;

            d[p] = 0;



            bool update = false;

            if(r==0)while(true)

            {

                update = false;

                rep(j,n*2)

                {

                   if(d[cs[j].a] != INF && d[cs[j].b] > d[cs[j].a] + cs[j].c)

                   {

                       update = true;

                       d[cs[j].b] =  d[cs[j].a] + cs[j].c;

                   }

                }

                if(!update) break;

            }

            if(r==1)while(true)

            {

                update = false;

                rep(j,n*2)

                {

                   if(d[cs[j].a] != INF && d[cs[j].b] > d[cs[j].a] + cs[j].t)

                   {

                       update = true;

                       d[cs[j].b] =  d[cs[j].a] + cs[j].t;

                   }

                }

                if(!update) break;

            }

            cout << d[q] << endl;

        }

        

    }



    return 0;

}