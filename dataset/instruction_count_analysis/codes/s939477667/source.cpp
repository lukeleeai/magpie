#include "stdc++.h"

using namespace std;

vector <long long> monedas;

long long memoria [100005];

int main ()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    long long c;

    long long res=0;

    memset(memoria,-1,sizeof(memoria));

    cin>>c;

    monedas.push_back(1);

    queue <pair <long long,long long> > que;

    que.push({1,1});

    memoria [0]=0;

    for (long long i=0, a=9,b=6;i<6;++i,a*=9,b*=6)

    {

        if (i==5)

        {

            monedas.push_back(b);

            que.push({b,1});

            continue;

        }

        monedas.push_back(a);

        que.push({a,1});

        monedas.push_back(b);

        que.push({b,1});

    }

    sort(monedas.begin(),monedas.end());

    while (!que.empty())

    {

        long long valor=que.front().first;

        long long costo=que.front().second;

        que.pop();

        if (valor==c)

        {

             printf("%lld\n",costo);

             return 0;

        }

        if (memoria[valor]!=-1)

            continue;

        memoria[valor]=costo;

        for (int i=0;i<monedas.size();i++)

        {

            if (monedas[i]+valor>c)

            {

                break;

            }

            if ( memoria[monedas[i]+valor]==-1)

            {

               que.push({monedas[i]+valor,costo+1});

            }

        }

 

    }

 

    //cout<<memoria[c]<<endl;

    return 0;

}