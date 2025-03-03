#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define maxn 100005

int n,p[maxn],pos[maxn],a[maxn],b[maxn],cnt[maxn];



int main()

{

    scanf("%d",&n);

    int N=n+1;

    for (int i=1;i<=n;i++) scanf("%d",p+i);

    for (int i=1;i<=n;i++) a[i]=N*i;

    for (int i=1;i<=n;i++) b[i]=(n-i+1)*N;

    for (int i=2;i<=n;i++)

        if (!cnt[p[i-1]]) b[p[i]]=(n-p[i]+1)*N+1,cnt[p[i]]=1;

        else b[p[i]]=(n-p[i]+1)*N+cnt[p[i-1]]+1,cnt[p[i]]=cnt[p[i-1]]+1;

    for (int i=1;i<n;i++) printf("%d ",a[i]);printf("%d\n",a[n]);

    for (int i=1;i<n;i++) printf("%d ",b[i]);printf("%d\n",b[n]);

    return 0;

}