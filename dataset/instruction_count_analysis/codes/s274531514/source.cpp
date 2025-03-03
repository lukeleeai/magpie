#include"stdc++.h"

#define N 100005

#define int long long

using namespace std;

int n,m,x[N],a[N],p[N],s[N],cnt;

long long k;

int be[N],num[N],v[N];

vector<int>q[N];

void dfs(int x,int dep)

{

    num[x]=dep;v[x]=1;be[x]=cnt;

    q[cnt].push_back(x);

    if(!v[p[x]])dfs(p[x],dep+1);

}

signed main()

{

    memset(v,0,sizeof(v));

    cin>>n;

    for(int i=1;i<=n;i++)cin>>x[i];

    for(int i=1;i<n;i++)s[i]=x[i+1]-x[i];

    cin>>m>>k;

    for(int i=1;i<n;i++)p[i]=i;

    for(int i=1;i<=m;i++){cin>>a[i];swap(p[a[i]],p[a[i]-1]);}

    for(int i=1;i<n;i++)if(!v[i])cnt++,dfs(i,0);

    cout<<x[1]<<endl;

    int now=x[1];

    for(int i=1;i<n;i++)

    {

        now+=s[q[be[i]][(num[i]+k)%q[be[i]].size()]];

        cout<<now<<endl;

    }

    return 0;

}