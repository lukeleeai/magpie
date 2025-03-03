#include<cstdio>

using namespace std;

int n,x,las,ans,c[200013];

int main(){

    scanf("%d",&n);

    ans=1;las=-1;

    for(register int i=0;i<n;++i){

        scanf("%d",&x);

        if(x==las)continue;

        las=x;

        ans=(1LL*ans+c[x])%1000000007;

        c[x]=ans;

    }

    printf("%d",ans);

    return 0;

}