#include"stdc++.h"

using namespace std;

#define ll long long int

#define ld long double

#define pii pair<int,int>

#define pll pair<ll,ll>

#define rep(n) for(int i=0;i<n;i+=1)

#define prarr(a,n) rep(n) cout<<a[i]<<endl printf("%s\n"," " );

#define sc(a) scanf("%d",&a);

#define scl(a) scanf("%lld",&a);

#define scf(a) ascanf("%f",&a);

#define fi first

#define se second

#define pu push_back

#define inf 1000000001

#define MOD 1000000007 

#define INF 100000000000001

const int MAXN = 2e5+10;

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    map<int,vector<int>> m;

    map<int,int> ans;

    int n;

    pii a[MAXN];

    int b[MAXN]={0};

    cin>>n;

    rep(n) 

    {

        cin>>a[i].fi;

        a[i].se = i;

        // m[a[i]].pu(i);

    }

    sort(a,a+n);

    rep(n)

    {

        if((i+1)<=n/2)

            ans[a[i].se] = a[n/2].fi;

        else

            ans[a[i].se] = a[n/2-1].fi;     

    }

    rep(n)

    {

        cout<<ans[i]<<endl; 

    }

    return 0;



}

    