#include "stdc++.h"

typedef long long ll;

using namespace std;

#define forn(i,n) for(int i=0;i!=n;i++)

ll n,c,g,a,we,ac,L[7],p[7],m,k,dp[500][500];

int main(){

cin>>n>>c,c*=n,m=n-1,k=1<<m;

forn(i,n)cin>>L[i],L[i]*=n;

sort(L,L+n);

iota(p,p+m,0);

do{

    memset(dp,0,sizeof(dp)),dp[L[m]][0]=1;

    forn(i,c)if(i%n){

        we = p[i%n-1];

        forn(mask,k)if(!((1<<we)&mask))

            for(ac=i;ac<=c;ac++)dp[max(ac,min(c,L[we]+i))][mask+(1<<we)]+=dp[ac][mask];

    }g+=dp[c][k-1],a++;

}while(next_permutation(p,p+m));

printf("%.15f",g/pow(c/n,m)/a);

}
