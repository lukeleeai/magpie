#include "stdc++.h"

#define MOD 1000000007

#define INF 1061109567

#define pb push_back

#define in(s) freopen(s,"r",stdin);

#define out(s) freopen(s,"w",stdout);

#define fi first

#define se second

#define bw(i,r,l) for (int i=r-1;i>=l;i--)

#define fw(i,l,r) for (int i=l;i<r;i++)

#define fa(i,x) for (auto i:x)

using namespace std;

const int N=1e5+5;

int n,L,q,x[N],sp[N][20];

int get(int x,int y) {

	int ans=1;

	bw (i,18,0) if (sp[x][i]!=-1&&sp[x][i]<y) x=sp[x][i],ans+=(1<<i);

	return ans;

}

signed main() {

	//in("aome.inp");

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;

	fw (i,0,n) cin>>x[i];

	cin>>L>>q;

	memset(sp,-1,sizeof(sp));

	fw (i,0,n) sp[i][0]=upper_bound(x,x+n,x[i]+L)-x-1;

	fw (j,1,18) fw (i,0,n) if (sp[i][j-1]!=-1) sp[i][j]=sp[sp[i][j-1]][j-1];

	while (q--) {

		int a,b; 

		cin>>a>>b;

		if (a>b) swap(a,b);

		cout<<get(a-1,b-1)<<"\n";

	}

	return 0;

}