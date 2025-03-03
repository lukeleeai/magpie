#include<cstdio>

int f[5007];

int min(int a,int b){return a<b? a:b;}

int main()

{

    int n,p,ans=0;

    scanf("%d%d",&n,&p),f[0]=1;

    for(int i=1;i<n;++i) for(int k=min(i,n-i+1),j=k;j<n;++j) (f[j]+=f[j-k])%=p;

    for(int i=0;i<n;++i) (ans+=1ll*(n-i)*f[i]%p)%=p;

    printf("%d",ans);

}