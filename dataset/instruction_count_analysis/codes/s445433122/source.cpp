#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;

typedef pair<int, int> Pi;

typedef vector<ll> Vec;

typedef vector<int> Vi;

typedef vector<string> Vs;

typedef vector<vector<ll>> VV;



#define REP(i, a, b) for(ll i=(a); i<(b); i++)

#define rep(i, n) REP(i, 0, n)

const ll INF=1e9;

const ll MAX=100005;

const ll MOD=1000000007;

#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;

#define YES(n) cout << ((n) ? "YES" : "NO") << endl;

#define ALL(v) v.begin(), v.end()

#define dbg(x_) cerr << #x_ << ":" << x_ << endl;

#define pb(x) push_back(x)

#define mp(a, b) make_pair(a,b)

#define Each(a,b) for(auto &a :b)

#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)

#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}

#define dbgarr(n,m,arr) rep(i,n){rep(j,n){cout<<arr[i][j]<<" ";}cout<<endl;}

#define sum(v) accumulate(ALL(v),0)

#define fi first

#define se second



template<typename T1, typename T2>

ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }



// vector

template<typename T>

ostream &operator<<(ostream &s, const vector<T> &v) {

    int len=v.size();

    for(int i=0; i<len; ++i) {

        s<<v[i];

        if(i<len-1) s<<"	";

    }

    return s;

}



// 2 dimentional vector

template<typename T>

ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {

    int len=vv.size();

    for(int i=0; i<len; ++i) {

        s<<vv[i]<<endl;

    }

    return s;

}



ll mpp[1003][1003] ;

struct Tuple{

    ll fi,se,th;

    Tuple(){};

    Tuple(ll a,ll b,ll c):fi(a),se(b),th(c){};

};

int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll h, w;

    cin>>h>>w;

    string tmp;

    ll ans=0;

    ll left=0;

    memset(mpp,-1, sizeof(mpp));

    queue<Tuple> q;

    rep(i,h){

        cin>>tmp;

        rep(j,tmp.length()){

            if(tmp[j]=='#'){

                mpp[i+1][j+1] = 1;

                q.push(Tuple(i+1+1,j+1,0));

                q.push(Tuple(i+1-1,j+1,0));

                q.push(Tuple(i+1,j+1+1,0));

                q.push(Tuple(i+1,j+1-1,0));

            }else{

                mpp[i+1][j+1] = 0;

                left++;

            }

        }

    }

//    dbg(left);

//    dbgarr(4,4,mpp);

//    while(!q.empty()){

//        dbg(q.front().th);

//        q.pop();

//

//    }

    if(left>0){

        while(left&&!q.empty()){

            Tuple &now = q.front();

            if(mpp[now.fi][now.se]==0){

                mpp[now.fi][now.se]=now.th+1;

                left--;

                ans = max(ans,now.th+1);

                q.push(Tuple(now.fi+1,now.se,now.th+1));

                q.push(Tuple(now.fi-1,now.se,now.th+1));

                q.push(Tuple(now.fi,now.se+1,now.th+1));

                q.push(Tuple(now.fi,now.se-1,now.th+1));

            }

            q.pop();

        }

    }

    //dbgarr(7,7,mpp);

    cout<<ans<<endl;

    return  0;

}
