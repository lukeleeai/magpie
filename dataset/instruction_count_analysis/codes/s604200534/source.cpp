#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;



const int MAXN=100005;

const int INF=0x3f3f3f3f;



ll sum[MAXN];

ll tot,ans=-INF;

int n,a[MAXN];

bool flag[MAXN];

char s[5];



int main(){

    scanf("%d%d",&n,&a[1]);

    for(int i=2;i<=n;i++){

        scanf("%s%d",s,&a[i]);

        if(s[0]=='-') flag[i]=1;

    }

    for(int i=n;i>=1;i--)

        sum[i]=sum[i+1]+a[i];

    int last=1;

    while(flag[last]==0&&last<=n){

        tot+=a[last];

        last++;

    }

    while(last<=n){

        int last1=last+1;

        ll tot1=0;

        while(flag[last1]==0&&last1<=n){

            tot1+=a[last1];

            last1++;

        }

        if(last1<=n)

            ans=max(ans,tot-tot1-a[last]+sum[last1]);

        tot-=a[last];

        last=last1;

        tot+=tot1;

    }

    ans=max(ans,tot);

    printf("%lld",ans);

}
