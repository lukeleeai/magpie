#include"stdc++.h"

using namespace std;

const int N=1005;

int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

long long x[N],y[N];

char ch[]={'U','D','R','L'};

int main() 

{

	ios::sync_with_stdio(false); 

	int n;

	cin>>n;

	for(int i=0;i<n;i++)

		cin>>x[i]>>y[i];

	int m2=0;

	if((x[0]+y[0])%2==0) 

	{

		m2=1;

		for(int i=0;i<n;i++)

			x[i]--;

	}

	for(int i=0;i<n;i++) 

	{

		if((x[i]+y[i])%2==0) 

		{

			cout<<-1<<endl;

			return 0;

		}

	}

	vector<long long>v;

	for(int i=0;i<=31;i++)

		v.push_back(1ll<<i);

	if(m2)

		v.push_back(1);

	reverse(v.begin(),v.end());

	cout<<v.size()<<endl;

	for(auto i=0;i<v.size();i++)

		cout<<v[i]<<" ";

	cout<<endl;

	for(int i=0;i<n;i++) 

	{

		string s;

		if(m2)

			s+="R";

		for(int j=31;j>=0;j--) 

		{

			int tmp=-1;

			long long now=LLONG_MAX;

			for(int k=0;k<4;k++) 

			{

				long long cur=abs(x[i]-dx[k]*(1ll<<j))+abs(y[i]-dy[k]*(1ll<<j));

				if(cur<now)

				{

					now=cur;

					tmp=k;

				}

			}

			x[i]-=dx[tmp]*(1ll<<j);

			y[i]-=dy[tmp]*(1ll<<j);

			s+=ch[tmp];

		}

		cout<<s<<endl;

	}

	return 0;

}

//