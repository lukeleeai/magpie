#include"stdc++.h"

using namespace std;

typedef long long ll;

const int maxn=2e5+7;

int a[maxn],cnt[maxn]={0};

ll pre[maxn]={0},jie[maxn];

void init()

{

    jie[0]=0;

    jie[1]=1;

    for(int i=2;i<maxn;++i)

        jie[i]=i+jie[i-1];

}

int main()

{

    ios::sync_with_stdio(false);

    //freopen("in.txt","r",stdin);

    init();

    int n;

    cin>>n;

    ll ans=0;

    set<int> st;

    map<ll,int> mp;

    for(int i=1;i<=n;++i){

        cin>>a[i];

        pre[i]=a[i]+pre[i-1];

        mp[pre[i]]++;

    }

    map<ll,int>::iterator it=mp.begin();

    for(;it!=mp.end();++it){

        if(it->first==0)

            ans+=jie[it->second];

        else

            ans+=jie[it->second-1];

    }

    cout<<ans<<endl;

    return 0;

}


