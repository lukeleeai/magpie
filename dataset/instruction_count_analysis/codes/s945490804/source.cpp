#include"stdc++.h"

#define p_ pair<int,int>

#define mp_ make_pair

#define ll long long

#define pb push_back

#define fi first

#define se second

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define show1(a) cout<<#a<<" = "<<a<<endl

#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl

using namespace std;

const ll INF = 1LL<<60;

const int inf = 1<<30;

const int maxn = 2e5+5;

inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int cnt[maxn];

int main()

{

    fastio();

    int n,k;

    cin>>n>>k;

    rep(i,1,k){

        int t;

        cin>>t;

        while(t--){

            int u;

            cin>>u;

            cnt[u]++;

        }

    }

    int ans = 0;

    rep(i,1,n) if(cnt[i]==0) ans++;

    cout<<ans<<endl;

    return 0;

}
