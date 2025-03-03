#include"stdc++.h"

using namespace std;

const int maxn=2e5+25;

#define ll long long int

#define INF 0x3f3f3f3f

int n;

int a[maxn];

ll sum[maxn];

ll b[5];

int main()

{

    int n;

    scanf("%d",&n);

    memset(sum,0,sizeof sum);

    for(int i=1;i<=n;i++){

        scanf("%d",&a[i]);

        sum[i]=sum[i-1]+a[i];

    }

    ll ans=-1;

    for(int i=2;i<=n-1;i++){

        ll s1=sum[i];

        ll s2=sum[n]-sum[i];

        ll x1,x2,y1,y2;

        ll av1=s1/2;ll av2=s2/2;

        // 1.0

        x1=lower_bound(sum+1,sum+i+1,av1)-sum;

        y1=lower_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));

        //cout<<ans<<endl;





        x1=lower_bound(sum+1,sum+i+1,av1)-sum;

        y1=lower_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        x1--;y1--;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));







        x1=lower_bound(sum+1,sum+i+1,av1)-sum;

        y1=lower_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        x1--;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));





        x1=lower_bound(sum+1,sum+i+1,av1)-sum;

        y1=lower_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        y1--;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));



        //2.0

        av1=s1/2;av2=s2/2;

        x1=upper_bound(sum+1,sum+i+1,av1)-sum;

        y1=lower_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));



        //3.0

        av1=s1/2;av2=s2/2;

        x1=lower_bound(sum+1,sum+i+1,av1)-sum;

        y1=upper_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));



        //4.0

        av1=s1/2;av2=s2/2;

        x1=upper_bound(sum+1,sum+i+1,av1)-sum;

        y1=upper_bound(sum+i+2,sum+1+n,s1+av2)-sum;

       // cout<<x1<<" "<<y1<<endl;

        b[1]=sum[x1];

        b[2]=s1-sum[x1];

        b[3]=sum[y1]-s1;

        b[4]=s2-b[3];

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        sort(b+1,b+5);

        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;

        if(ans==-1){

            ans=abs(b[4]-b[1]);

        }

        ans=min(ans,abs(b[4]-b[1]));



    }

    printf("%lld\n",ans);

    return 0;

}
