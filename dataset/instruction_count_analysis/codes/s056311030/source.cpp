#include"stdc++.h"

using namespace std;

string s;

long long l,r;

int p;

int n;

long long num[200010][26];

vector<int>zfunc()

{

	vector<int>z(1000010);

	int l=0,r=0;

	int ln=s.size();

	for(int k=2;k<=ln;k++)

	{

		if(s[k-1]!=s[0])continue;

		if(k>r)

		{

			l=r=k;

			while(r<=ln&&s[r-1]==s[r-l])r++;

			r--;

			z[k]=r+1-l;

		}

		else

		{

			int tk=k+1-l;

			if(z[tk]<r+1-k)

				z[k]=z[tk];

			else

			{

				l=k;

				while(r<=ln&&s[r-1]==s[r-l])r++;

				r--;

				z[k]=r+1-l;

			}

		}

	}

	return z;

}

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

	vector<int>z=zfunc();

	for(int i=n+2;i<=2*n;i++)

	{

		if(i+z[i]==2*n+1)

		{

			p=z[i];

			break;

		}

	}

	p=n-p;

	for(int i=1;i<=n;i++)

	{

		for(int j=0;j<26;j++)num[i][j]+=num[i-1][j];

		num[i][s[i-1]-'a']++;

	}

	for(int i=0;i<26;i++)cout<<sol(r,i)-sol(l-1,i)<<" ";

	cout<<endl;

	return 0;

}