#include<cstdio> 

#include<algorithm>

#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

typedef long long ll;

const int maxn=3000+10,mo=1000000007;

int f[maxn][maxn],right[maxn],sum[maxn];

int i,j,k,l,r,t,n,m,ans,one,zero;

char get(){

    char ch=getchar();

    while (ch!='0'&&ch!='1') ch=getchar();

    return ch;

}

int main(){

    scanf("%d%d",&n,&m);

    fo(i,1,n) sum[i]=get()-'0';

    fo(i,1,n+1) sum[i]+=sum[i-1];

    fo(i,1,n+1) right[i]=i;

    fo(i,1,m){

        scanf("%d%d",&j,&k);

        right[j]=max(right[j],k);

    }

    fo(i,1,n) right[i]=max(right[i],right[i-1]);

    f[1][sum[right[1]]]=1;

    fo(i,1,n)

        fo(j,0,n)

            if (f[i][j]){

                l=right[i]+1;r=right[i+1];

                one=j;zero=right[i]-i+1-j;

                if (zero) (f[i+1][j+sum[r]-sum[l-1]]+=f[i][j])%=mo;

                if (one) (f[i+1][j-1+sum[r]-sum[l-1]]+=f[i][j])%=mo;

            }

    ans=f[n+1][0];

    (ans+=mo)%=mo;

    printf("%d\n",ans);

}