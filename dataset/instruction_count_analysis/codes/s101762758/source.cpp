#include"stdc++.h"

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))

#define min(x,y) ((x)<(y)?(x):(y))

typedef long long ll;

typedef pair<int,int> pii;

const int maxn=1010;

map<int,int> cnt,tmp;

vector<int> gt[100001];

struct req {long long x; long long d;};

deque<req> q;

int n,a,b,i,j,m,c,d,k;

int fac[8]={1,1,2,6,24,120,720,5040};

vector<string> prim; string cur;

vector<int> fin={2,3,5,7};

int p(int x)

{

	int a=sqrt(x);

	for (int i=2;i<=a;i++) if (x%i); else return 0;

	return 1;

}

int cmp (string a, string b)

{

	if (a.length()-b.length()) return (a.length()<b.length());

	return (a<b);

}

int expect(string a)

{

	int n=a.length(),cnt1=0,cnt3=0,cnt7=0,cnt9=0;

	for (int i=0;i<n;i++)

	{

		if (a[i]=='1') cnt1++;

		if (a[i]=='3') cnt3++;

		if (a[i]=='7') cnt7++;

		if (a[i]=='9') cnt9++;

	}

	return fac[n]/fac[cnt1]/fac[cnt3]/fac[cnt7]/fac[cnt9];

}

int conv (string a)

{

	int n=a.length(),res=0;

	for (int i=0;i<n;i++)

	{

		res*=10;

		res+=a[i]-48;

	}

	return res;

}

void build(int i)

{

	if ((i>=2)and(p(c))) {sort(cur.begin(),cur.end()); prim.push_back(cur);}

	if (i<7)

	{

		cur.push_back('1');

		c*=10;

		c+=1;

		build(i+1);

		cur.pop_back();

		cur.push_back('3');

		c-=1;

		c+=3;

		build(i+1);

		cur.pop_back();

		cur.push_back('7');

		c-=3;

		c+=7;

		build(i+1);

		cur.pop_back();

		cur.push_back('9');

		c-=7;

		c+=9;

		build(i+1);

		cur.pop_back();

		c-=9;

		c/=10;

	}

}

int main()

{

	#define endl "\n"

//	freopen("janitorin.txt","r",stdin);

//	freopen("janitorout.txt","w",stdout);

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	int n,k,s;

	cin>>n>>k>>s;

	

	{

		

	for (i=0;i<n;i++) if (i<k) cout<<s<<' '; else if (s<1e9) cout<<s+1<<' '; else cout<<s-1<<' ';

	}

}