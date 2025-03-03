#include"stdc++.h"

#define swap mswap

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

#define int long long 

using namespace std;

const int big=0x7fffffffffffff;

void swap(int &x,int &y)

{

    x^=y^=x^=y;

}

void read(int &x)

{

    x=0;

    char ch=getchar();

    int pd=1;

    while(ch<'0'||ch>'9')

    {

        if(ch=='-')

        {

            pd=-pd;

        }

        ch=getchar();

    }

    while(ch<='9'&&ch>='0')

    {

        x=x*10+ch-'0';

        ch=getchar();

    }

    x*=pd;

}

void write(const int &x)

{

    char f[100001];

    int s=0;

    int tmp=x;

    if(tmp==0)

    {

        putchar('0');

        return;

    }

    if(tmp<0)

    {

        tmp=-tmp;

        putchar('-');

    }

    while(tmp>0)

    {

        f[s++]=tmp%10+'0';

        tmp/=10;

    }

    while(s>0)

    {

        putchar(f[--s]);

    }

}



const int mod=1e9+7;

const int N=2e5+10;

int jie[N],ni[N],n,A,B;

int c[N],w[N],minn[N],cnt[N];

int sum,ans=1;

int ksm(int x,int y)

{

	int ans=1;

	while(y)

	{

		if(y&1)

		{

			ans=(ans*x)%mod;

		}

		x=(x*x)%mod;

		y>>=1;

	}

	return ans%mod;

}

int zuhe(int x,int y)

{

	return ((jie[x]*ni[y])%mod*ni[x-y])%mod;

}

signed main()

{

//	freopen("keep.in","r",stdin);

//	freopen("keep.out","w",stdout);

	jie[0]=1;

	read(n);

	read(A);

	read(B);

	for(register int i=1;i<=n;++i)

	{

		read(c[i]);

		read(w[i]);

		minn[i]=big;

		cnt[c[i]]++;

		jie[i]=jie[i-1]*i%mod;

	}

	

	ni[n]=ksm(jie[n],mod-2);

	for(register int i=n-1;i>=0;--i)

	{

		ni[i]=(ni[i+1]*(i+1))%mod;

//		cout<<ni[i]<<endl;

	}

	

//	cout<<zuhe(3,1)<<"   QWQ"<<endl;

	for(register int i=1;i<=n;++i)

	{

		minn[c[i]]=min(minn[c[i]],w[i]);

	}

	int min1=0,allmin=0;

	for(register int i=1;i<=n;++i)

	{

		if(minn[i]!=big)

		{

			if(!min1||minn[i]<minn[min1])

			{

				allmin=min1;

				min1=i;

			}

			else 

			{

				if(!allmin||minn[i]<minn[allmin])

				{

					allmin=i;

				}

			}

		}

	}

	for(register int i=1;i<=n;++i)

	{

		if(minn[c[i]]!=w[i]&&w[i]+minn[c[i]]<=A)continue;

		if(c[i]==min1&&w[i]+minn[allmin]<=B)continue;

		if(c[i]!=min1&&w[i]+minn[min1]<=B)continue;

		cnt[c[i]]--;

	}

	sum=cnt[min1];

	for(register int i=1;i<=n;++i)

	{

		if(i!=min1&&minn[i]+minn[min1]<=B)

		{

			sum+=cnt[i];

//			cout<<sum<<endl;

			ans=(ans*zuhe(sum,cnt[i]))%mod;

//			cout<<ans<<endl;

		}

	}

	write(ans);

}
