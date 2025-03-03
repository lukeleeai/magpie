/* おまじない　*/

#include "stdc++.h"

#pragma GCC optimize("Ofast")

typedef long long ll;

typedef long double ld;

using namespace std;

const ll MOD=pow(10,9)+7;

const ll INF=(1LL<<62);

const int dx[4]={0,1,0,-1};

const int dy[4]={1,0,-1,0};

const int ddx[8]={1,0,-1,-1,-1,0,1,1};

const int ddy[8]={1,1,1,0,-1,-1,-1,0};

void init(){

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

}





int main() {

    int n, x;

    ll Q,H,S,D;

    cin>>Q>>H>>S>>D;

    ll N;cin>>N;

    if(N%2==0){

        N=N/2;

        cout<<min(Q*N*8,min(H*N*4,min(S*N*2,N*D)))<<endl;

    }else{

        ll ans=0;

        N=N/2;

        ans+=min(Q*N*8,min(H*N*4,min(S*N*2,N*D)));

        ans+=min(Q*4,min(H*2,S*1));

        cout<<ans<<endl;

    }



}
