#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define fbo find_by_order

#define ook order_of_key



typedef long long ll;

typedef pair<ll,ll> ii;

typedef vector<int> vi;

typedef long double ld; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;



int dp1[100001];

int dp2[100001];



int sum1(int l, int r)

{

	if(l==0) return dp1[r];

	else return dp1[r]-dp1[l-1];

}



int sum2(int l, int r)

{

	if(l==0) return dp2[r];

	else return dp2[r]-dp2[l-1];

}





int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	string s, t;

	cin>>s>>t;

	int q; cin>>q;

	int n = s.length(); int m = t.length();

	for(int i=0;i<n;i++)

	{

		if(s[i]=='A') dp1[i]=1;

		else dp1[i]=-1;

		if(i>0) dp1[i]+=dp1[i-1];

	}

	for(int i=0;i<m;i++)

	{

		if(t[i]=='A') dp2[i]=1;

		else dp2[i]=-1;

		if(i>0) dp2[i]+=dp2[i-1];

	}

	while(q--)

	{

		int l1,r1,l2,r2;

		cin>>l1>>r1>>l2>>r2;

		l1--;r1--;l2--;r2--;

		int s1 = sum1(l1,r1);

		int s2 = sum2(l2,r2);

		s1-=s2;

		if(s1<0) s1=-s1;

		if(s1%3==0)

		{

			cout<<"YES\n";

		}

		else

		{

			cout<<"NO\n";

		}

	}

}
