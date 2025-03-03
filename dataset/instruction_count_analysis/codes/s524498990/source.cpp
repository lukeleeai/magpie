#include "stdc++.h"

#define ll long long

#define INF 1000000005

#define MOD 1000000007

#define EPS 1e-10

#define rep(i,n) for(int i=0;i<n;++i)



using namespace std;



typedef pair<int,int>P;



const int MAX_N = 100005;



int p,q,a,n;

ll res;



P compute(int nume,int deno,int nw)

{

    P p;

    p.first = nume*nw + deno;

    p.second = deno * nw;

    return p;

}



void dfs(int mn,int nume,int deno,int cnt)

{

    if(deno*p == nume*q){

        res++;

        return;

    }

    if(cnt == n){

        return;

    }

    if(deno*p < nume*q){

        return;

    }

    for(int i=mn;i<=a/deno;i++){

        P p = compute(nume,deno,i);

        dfs(i,p.first,p.second,cnt+1);

    }

    return;

}



int main()

{

    while(1){

        scanf("%d%d%d%d",&p,&q,&a,&n);

        if(p == 0 && q == 0 && a == 0 && n == 0){

            break;

        }

        res = 0;

        rep(i,12000){

            dfs(i+1,1,i+1,1);

        }

        printf("%lld\n",res);

    }

	return 0;

}