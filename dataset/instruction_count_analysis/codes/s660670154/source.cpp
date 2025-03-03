#include <cstdio>

using namespace std;

int N,P,cur,t=1,cnt[10010],i;char S[200010];long long ans;

int main()

{

    scanf("%d%d%s",&N,&P,S);

    if(P==2||P==5){

        for(i=0;i<N;i++)if((S[i]-'0')%P==0)ans+=i+1;

    }else{

        cnt[0]=1;

        for(i=N-1;i>=0;i--){

            (cur+=(S[i]-'0')*t)%=P;

            ans+=cnt[cur]++;

            t=t*10%P;

        }

    }

    printf("%lld",ans);

}