#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cstring>

using namespace std;

typedef long long ll;

#define N 400102

const int p=998244353,iv=499122177;

int n,ps[N],m,a[N];

inline int ksm(int d,int k){int ret=1;while(k){if(k&1)ret=1ll*ret*d%p;d=1ll*d*d%p;k>>=1;}return ret;}

inline void fwt(int x[],int len,int mde)

{

    for(int i=2;i<=len;i<<=1)for(int j=0,stp=i>>1;j<len;j+=i)for(int k=j;k<j+stp;k++)

    {

        int t1=x[k],t2=x[k+stp];x[k]=(t1+t2)%p,x[k+stp]=(t1-t2+p)%p;

        if(mde<0)x[k]=1ll*x[k]*iv%p,x[k+stp]=1ll*x[k+stp]*iv%p;

    }

}

int main()

{

    scanf("%d",&n);m=(1<<n);int sum=0;

    for(int i=0;i<m;i++)scanf("%d",&ps[i]),sum=(sum+ps[i])%p;sum=ksm(sum,p-2)%p;

    for(int i=0;i<m;i++)ps[i]=1ll*ps[i]*sum%p;

    a[0]=m-1;for(int i=1;i<m;i++)a[i]=p-1;

    ps[0]=(ps[0]+p-1)%p;

    fwt(a,m,1);fwt(ps,m,1);

    for(int i=0;i<m;i++)a[i]=1ll*a[i]*ksm(ps[i],p-2)%p;

    a[0]=0;

    fwt(a,m,-1);

    for(int i=1;i<m;i++)a[i]=(a[i]-a[0]+p)%p;

    a[0]=0;

    for(int i=0;i<m;i++)printf("%d\n",a[i]);

}
