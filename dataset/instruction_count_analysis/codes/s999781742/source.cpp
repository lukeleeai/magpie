#include"stdc++.h"

using namespace std;

const int pi=3.1415926535897932384626433832795;

const int dx[]={0,1,0,-1};

const int dy[]={1,0,-1,0};

#define ll long long

#define inf int(1e9+7)

#define pb push_back

#define mp make_pair

void solve(int n,string s,int t1,int t2)

{

	vector<int>sh(n);

	sh[0]=t1;

	sh[1]=t2;

	for(int i=2;i<n;i++)

		sh[i]=(sh[i-1]+sh[i-2]+(s[i-1]=='x'))%2;

	if((sh[n-1]+sh[0]+sh[1]+(s[0]=='x'))%2==0&&(sh[n-2]+sh[n-1]+sh[0]+(s[n-1]=='x'))%2==0)

	{

		for(int i=0;i<n;i++)

			cout<<(sh[i]?'W':'S');

		exit(0);

	}		

}

int main()

{

	int n;

	string s;

	cin>>n>>s;

	solve(n,s,0,0);

	solve(n,s,0,1);

	solve(n,s,1,0);

	solve(n,s,1,1);

	puts("-1");

}