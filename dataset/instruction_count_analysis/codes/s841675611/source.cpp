#include"stdc++.h"

using namespace std;



#define f first

#define s second

#define pb push_back

#define mp make_pair

#define ll long long int 

typedef pair<int,int> pii;

vector<int>v;

map<int,int>op;

#define MAX 200005

bool visited[MAX];

vector<int>adj[MAX];

const int M=1e9+7;

int n,m;

const ll INF = 1LL << 60;



string lcs(string a,string b)

{

	int al=a.length(),bl=b.length();

	int dp[al+1][bl+1];

	for(int i=0;i<=al;i++)

	{

		for(int j=0;j<=bl;j++)

		{

			if(i==0 || j==0)

				dp[i][j]=0;

			else if(a[i-1]==b[j-1])

				dp[i][j]=dp[i-1][j-1]+1;

			else

				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

		}

	}

	int index=dp[al][bl];

	string l="";

	int i=al,j=bl;

	while(i>0 && j>0)

	{

		if(a[i-1]==b[j-1])

		{

			l+=a[i-1];

			i--,j--,index--;

		}

		else if(dp[i-1][j] > dp[i][j-1]){

			i--;

		}

		else

			j--;	

	}

	reverse(l.begin(),l.end());

	return l;

}

int main()

{

	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	string a,b;

	cin>>a>>b;

	cout<<lcs(a,b)<<endl;

	return 0;	

}
