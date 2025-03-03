#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<string>

#include <iomanip>

#include<list>

using namespace std;

namespace D

{

	const int amaxn = 1005;  

	int donkey[amaxn][amaxn];  

	int tiger[amaxn][amaxn];  

	bool don,tig,flag;  

	int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

	int n;

	bool check(int x,int y,int t,int n)

	{

		if (x<0 || y<0 || x>=n || y>=n || t==1)

		{

			return 1;

		}

		return 0;

	}

	void dfs(int a,int b,int c,int x,int y,int z)  

	{  

	    donkey[a][b]=1;  

	    tiger[x][y]=1;  

	    if (flag)  

	        return;  

	    if (a==x && b==y)

	    {  

	        flag=1;  

	        printf("%d %d\n",a,b);  

	        return;  

	    }  

	    if (don && tig)

	    {  

	        flag=1;  

	        printf("-1\n");  

	        return;  

	    }  

	    int dx,dy,da,db;  

	    if (don)  

	    {  

	         da= a;  

	         db = b;       

	    }  

	    else  

	    {  

	        da = a+dir[c][0];  

	        db = b+dir[c][1];  

	        if (check(da,db,donkey[da][db],n))

	        {  

	            c = (c+1)%4;  

	            da = a+dir[c][0];  

	            db = b+dir[c][1];  

	            if (check(da,db,donkey[da][db],n))  

	            {  

	                don=1;  

	                da=a;  

	                db=b;  

	            }  

	        }  

	    }  

	    if (tig)  

	    {  

	        dx = x;  

	        dy = y;  

	    }  

	    else  

	    {  

	        dx = x+dir[z][0];  

	        dy = y+dir[z][1];  

	        if (check(dx,dy,tiger[dx][dy],n))  

	        {  

	            z = (z+3)%4;  

	            dx = x+dir[z][0];  

	            dy = y+dir[z][1];  

	            if (check(dx,dy,tiger[dx][dy],n))  

	            {  

	                tig = 1;  

	                dx = x;  

	                dy = y;  

	            }  

	        }  

	    }  

	    dfs(da,db,c,dx,dy,z);  

	}

	void D()  

	{

	    while (scanf("%d",&n)!=EOF && n)  

	    {  

	        memset(donkey,0,sizeof(donkey));  

	        memset(tiger,0,sizeof(tiger));  

	        tig=0;  

	        don=0;  

	        flag=0;  

	        int a,b,c,x,y,z;  

	        scanf("%d%d%d",&a,&b,&c);  

	        scanf("%d%d%d",&x,&y,&z);  

	        dfs(a,b,c,x,y,z);  

	    }  

	}

}

namespace A

{

/*

	1.   整数的唯一分解定理：

      任意正整数都有且只有一种方式写出其素因子的乘积表达式。

      A=(p1^k1)*(p2^k2)*(p3^k3)*....*(pn^kn)   其中pi均为素数

	2.   约数和公式：

	对于已经分解的整数A=(p1^k1)*(p2^k2)*(p3^k3)*....*(pn^kn)

	有A的所有因子之和为

	    S = (1+p1+p1^2+p1^3+...p1^k1) * (1+p2+p2^2+p2^3+….p2^k2) * (1+p3+ p3^3+…+ p3^k3) * .... * (1+pn+pn^2+pn^3+...pn^kn)

	3.   同余模公式：

	(a+b)%m=(a%m+b%m)%m

	(a*b)%m=(a%m*b%m)%m

*/

	const int mod=9901;

	const int a_maxn=5000100;

	typedef long long ll;

	ll q_pow(ll a,ll b)

	{

		ll ans=1;

		a=a%mod;

		while(b)

		{

			if(b&1)

				ans=ans*a%mod;

			a=a*a%mod;

			b>>=1;

		}

		return ans%mod;

	}

	ll getreverse(ll x)

	{

		return q_pow(x,(ll)(mod-2))%mod;

	} 

	ll sum(ll p,ll k,ll b)

	{  

	    ll tm = (q_pow(p,k*b+(ll)1)-(ll)1)%mod;

	    ll reverse = getreverse(p-(ll)1)%mod;

	    return tm*reverse%mod;

	}

	

	ll p[a_maxn],k[a_maxn];

	ll resolve(ll& a)

	{

		ll cnt=0;

		for(ll i=2;i*i<=a;i++)

		{

			if(a%i==0)

			{

				p[cnt]=i;

				k[cnt]=0;

				while(a%i==0)

				{

					a/=i;

					k[cnt]++;

				}

				cnt++;

			}

		}

		if(a!=1)

		{

			p[cnt]=a;

			k[cnt]=1;

			cnt++;

		}

		return cnt;

	}

	ll sum2(ll p,ll n)

	{

		if(n==0)	return 1;

		if(n&1)

			return ((1+q_pow(p,(n>>1)+1))%mod*sum2(p,n>>1)%mod)%mod;

		else

			return ((1+q_pow(p,(n>>1)+1)%mod)*sum2(p,n>>1)%mod+q_pow(p,n>>1)%mod)%mod;

	}

	void A()

	{  

	    ll a,b,ans=1;

	    cin>>a>>b;

	    ll cnt=resolve(a);

	    for(ll i=0;i<cnt;i++)

	    {

	    	if((p[i]-1)%mod==0)

	    		ans=ans*(1+b*k[i])%mod;

	    	else

	    		ans=ans*sum(p[i],k[i],b)%mod;

		}

		//for(ll i=0;i<cnt;i++)	ans=ans*sum2(p[i],b*k[i])%mod;

	    while(ans<0)

	        ans += mod;

	    cout<<ans<<endl;

	}

}



namespace B

{

	const int b_maxn=1e6+10;

	int dp_b[b_maxn],a[b_maxn];

	void B()

	{

		int n,k,num,value;

		while(cin>>n>>k)

		{

			int cnt=0;

			for(int i=0;i<k;i++)

			{

				cin>>num>>value;

				if(num==0&&value==0)

					continue;

				int tm=1;

				while(num-tm>0)

				{

					a[cnt++]=value*tm;

					num-=tm;

					tm*=2;

				}

				a[cnt++]=num*value;

			}

			memset(dp_b,0,sizeof(dp_b));

			for(int i=0;i<cnt;i++)

			{

				for(int j=n;j>=a[i];j--)

				{

					dp_b[j]=max(dp_b[j],dp_b[j-a[i]]+a[i]);

				}

			}

			cout<<dp_b[n]<<endl;

		}

	}

}



namespace C

{

	struct Node

	{

		int l,r,sum;

		Node():l(0),r(0),sum(0){};

	};

	const int maxn=1e5+10;

	Node tree[maxn<<2];

	int ans[maxn],pc[maxn],vc[maxn];

	void push_up(int now)

	{

		tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;

	}

	void build(int now,int x,int y)

	{

	    tree[now].l = x,tree[now].r = y;

	    tree[now].sum=y-x+1;

	    if(x==y)

	    {

	        return;

	    }

	    int mid = (x+y)>>1;

	    build(now<<1,x,mid);

	    build(now<<1|1,mid+1,y);

	}

	void update(int now,int p,int v)

	{

		int l=tree[now].l;

		int r=tree[now].r;

		int mid=(l+r)>>1;

		if(l==r)

		{

			tree[now].sum=0;

			ans[l]=v;

			return;

		}

		if(tree[now<<1].sum>=p)

			update(now<<1,p,v);

		else

			update(now<<1|1,p-tree[now<<1].sum,v);

		push_up(now);

	}

	void C()

	{

		int n;

		cin>>n;

		while(cin>>n)

		{

			build(1,1,n);

			for(int i=0;i<n;i++)

				cin>>pc[i]>>vc[i];

			for(int i=n-1;i>=0;i--)

				update(1,pc[i]+1,vc[i]);

			for(int i=0;i<n;i++)

				cout<<ans[i]<<" ";

			cout<<endl;

		}

	}

}

namespace G

{

	const int maxn=2e5+10;

	int a[maxn];

	void solve()

	{

		int n;

		cin>>n;

		for(int i=1;i<=n;i++)

		{

			int t;cin>>t;

			a[t]=i;

		}

		int ans=maxn,len=1;

		for(int i=1;i<n;i++)

		{

			if(a[i+1]>a[i]) len++;

			else

			{

				ans=min(ans,n-len);

				len=1;

			}

		}

		cout<<min(ans,n-len)<<endl;

	}

}

int main()

{

	ios::sync_with_stdio(false);

	G::solve();

	return 0;

}
