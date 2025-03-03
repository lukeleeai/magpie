#include "stdc++.h"

typedef long long ll;

using namespace std;

#define forn(i,n) for(int i=0;i!=n;i++)

ll n,c,g,a,ac,L[7],m,k,dp[500][500];

int main(){

cin>>n>>c,c*=n,m=n-1,k=1<<m;

forn(i,n)cin>>L[i],L[i]*=n;

sort(L,L+n);

do{

    memset(dp,0,sizeof(dp)),dp[L[m]][0]=1;

    forn(i,c)if(i%n){

        forn(mask,k)if(!((1<<(i%n-1))&mask))

            for(ac=i;ac<=c;ac++)dp[max(ac,min(c,L[i%n-1]+i))][mask+(1<<(i%n-1))]+=dp[ac][mask];

    }g+=dp[c][k-1],a++;

}while(next_permutation(L,L+m));

printf("%.15f",g/pow(c/n,m)/a);

}
