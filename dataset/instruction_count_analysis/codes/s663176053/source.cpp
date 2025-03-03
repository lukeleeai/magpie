#include"stdc++.h"

using namespace std;

typedef int ll;

typedef double db;

typedef pair<ll,ll> P;

#define pb push_back

#define ft first

#define sd second

#define mp make_pair

#define fr(i,n) for(int i=0;i<(n);i++)

#define Fr(i,n) for(int i=0;i++<(n);)

#define ifr(i,n) for(int i=(n)-1;i>=0;i--)

#define iFr(i,n) for(int i=(n);i>0;i--)



void cc(ll a,map<ll,bool>& ap,map<ll,ll>& nm,vector<ll>& c){

    if(!ap[a]){

        ap[a]=1;

        nm[a]=c.size();

        c.pb(a);

    }

}



ll n;

const ll INF=1e9+1;

vector<ll> dat(2400010,INF);



void init(ll n_){

    n=1;

    while(n<n_) n*=2;



}



void ud(ll be,ll en,ll t,ll k=0,ll l=0,ll r=n){

    if(en<=l||r<=be) return;

    if(be<=l&&r<=en){

        dat[k]=t;

        return;

    }

    ud(be,en,t,k*2+1,l,(l+r)/2);

    ud(be,en,t,k*2+2,(l+r)/2,r);

    return;

}



ll gt_sub(ll k){

    if(k==0) return dat[k];

    return min(dat[k],gt_sub((k-1)/2));

}



ll gt(ll i){

    return gt_sub(i+n-1);

}





int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll N=0,M,q,A,B,C;

    map<ll,bool> ap;map<ll,ll> nm;vector<ll> c,a;

    cin>>M>>q;

    vector<ll> d(q);

    vector<pair<ll,pair<ll,ll>>> xst;

    fr(i,M){

        cin>>A>>B>>C;

        if(B<C) continue;

        if(A<C) A=C;

        xst.emplace_back(C,mp(A,B));

        a.pb(xst[N].ft);

        if(A>C) a.pb(A-C);

        a.pb(B-C);

        N++;

    }

    sort(xst.begin(),xst.end(),greater<pair<ll,pair<ll,ll>>>());

    fr(i,q){

        cin>>d[i];

        a.pb(d[i]);

    }

    a.pb(0);

    sort(a.begin(),a.end());

    fr(i,a.size()) cc(a[i],ap,nm,c);

    init(a.size()+1);

    fr(i,N){

        ud(nm[-(xst[i].ft-xst[i].sd.ft)],nm[-(xst[i].ft-xst[i].sd.sd)],xst[i].ft);

        //fr(i,c.size()) cout<<gt(i)<<" ";

        //cout<<endl;

    }

    fr(i,q){

        ll ans=gt(nm[d[i]]);

        if(ans==INF) cout<<-1<<endl;

        else cout<<ans<<endl;

    }

}