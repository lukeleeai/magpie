#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;

inline int rd(){

    char c=getchar();int x=0,flag=1;

    for(;c<'0'||c>'9';c=getchar())if(c=='-')flag=-1;

    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';

    return x*flag;

}

int n,nw[500010],d[500010],f[500010];

int main(){

//  freopen("a.in","r",stdin);

    n=rd();nw[0]=rd();f[n+1]=1;

    for(int i=1;i<=n;i++)

        d[i]=rd();

    for(int i=1;i<=n;i++)

        nw[i]=min(nw[i-1],abs(nw[i-1]-d[i]));

    for(int i=n;i;i--)

        f[i]=(f[i+1]<=d[i]/2)?f[i+1]:f[i+1]+d[i];

    for(int i=rd();i;i--){

        int x=rd();

        puts(nw[x-1]>=f[x+1]?"YES":"NO");

    }

    return 0;

}