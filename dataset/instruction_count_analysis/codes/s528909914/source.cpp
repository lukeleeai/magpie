#include"stdc++.h"

using namespace std;

string s;

long long l,r;

int p;

int n;

int f[100005];

long long num[200010][26];

long long doit(long long x,int y)

{

	if(x<=n)return num[x][y];

	if(x<=2*n)return num[n][y]+num[x-n][y];

	long long x1=num[n][y]+num[p][y],x2=num[n][y];

	long long l1=n+p,l2=n;

	while(x>l1+l2)

	{

//		cout<<x1<<" "<<x2<<" "<<l1<<" "<<l2<<endl;

		long long t=x1;

		x1+=x2;

		x2=t;

		t=l1;

		l1+=l2;

		l2=t;

	}

	x1+=doit(x-l1,y);

//	cout<<x<<" "<<x1<<endl;

	return x1;

}

long long sol(long long x,int y)

{

	if(x<=n)return num[x][y];

//	if(x<=2*n)return num[n][y]+num[x-n][y];

	if(n%p==0)

	{

		long long xx=(x-n)/(long long)p*num[p][y]+num[n][y];

		x%=(long long)p;

		xx+=num[x][y];

		return xx;

	}

	return doit(x,y);

}

int main()

{

	cin>>s>>l>>r;

	n=s.size()/2;

	s=s.substr(0,n);

	s=" "+s;

	f[1]=0;

	for(int i=2,j=0;i<=n;i++)

	{

		while(s[i]!=s[j+1]&&j>0)j=f[j];

		j+=(s[i]==s[j+1]);

		f[i]=j;

	}

//	cout<<f[0]<<f[1]<<f[2]<<f[3]<<endl;

	p=n-f[n];

//	cout<<p<<endl;

//	p=n-p;

	for(int i=1;i<=n;i++)

	{

		for(int j=0;j<26;j++)num[i][j]+=num[i-1][j];

		num[i][s[i]-'a']++;

	}

	for(int i=0;i<26;i++)cout<<sol(r,i)-sol(l-1,i)<<" ";

	cout<<endl;

	return 0;

}