#include <cstdio>

#include <algorithm>

using namespace std;

const int maxn=1e6+10,inf=1e9+7;

typedef long long ll;

ll h,w,node[maxn],n,a,b,cnt=0,zero,ans[15];

int main(){

    scanf("%lld%lld%lld",&h,&w,&n);

    zero=(h-2)*(w-2);

    while(n--){

        scanf("%lld%lld",&a,&b);

        for (int i=-2;i<=0;i++){

            for (int j=-2;j<=0;j++){

                if(a+i>=1 && a+i <=h-2 && b+j>=1 &&b+j <=w-2){

                    node[cnt++]=inf*(a+i)+(b+j);

                }

            }

        }

    }

    sort(node,node+cnt);

    for (int i=0,tmp=1;i<cnt;i++){

        if(node[i]==node[i+1]) tmp++;

        else ans[tmp]++,zero--,tmp=1;

    }

    printf("%lld\n",zero);

    for (int i=1;i<10;i++)

        printf("%lld\n",ans[i]);

    return 0;

}