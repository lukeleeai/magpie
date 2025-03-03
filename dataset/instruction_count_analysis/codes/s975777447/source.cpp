#include "stdc++.h"

using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)

#define REP(i,n) rep(i,0,n)



void solve() 

{

    int n,p;string s;cin>>n>>p>>s;

    int64_t ans=0;

    if(p==2||p==5){

        REP(i,n)if(!((s[i]-'0')%p))ans+=i+1;

    }else{

        map<int,int>cnt;

        cnt[0]=1;

        int cur=0,ten=1;

        REP(i,n){

            (cur+=(s[n-1-i]-'0')*ten)%=p;

            ans+=cnt[cur]++;

            (ten*=10)%=p;

        }

    }

    cout<<ans<<endl;

}



int main()

{

    cin.tie(0);

	ios::sync_with_stdio(false);

    solve();

    return 0;

}
