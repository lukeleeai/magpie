#include"stdc++.h"

using namespace std;

typedef long long ll;

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



template<class T> struct SintMIN{

    int n;

    T e;

    vector<T> dat;



    SintMIN(T n_,T e_){

        n=1;e=e_;

        while(n<n_) n*=2;

        dat.resize(2*n-1,e);

    }



    void ud(int be,int en,T t,int k,int l,int r){

        if(r<=be||en<=l) return ;

        if(be<=l&&r<=en){

            dat[k]=min(dat[k],t);

            return;

        }

        ud(be,en,t,k*2+1,l,(l+r)/2);

        ud(be,en,t,k*2+2,(l+r)/2,r);

    }



    void ud(int be,int en,T t){

        ud(be,en,t,0,0,n);

    }



    T gt_sub(int k){

        if(k==0) return dat[k];

        return min(dat[k],gt_sub((k-1)/2));

    }



    T gt(int i){

        return gt_sub(i+n-1);

    }

};



template<class T> void cc(vector<T> a,map<T,int>& nm,vector<int>& c){

    sort(a.begin(),a.end());

    fr(i,a.size()){

        if(i<a.size()-1&&a[i]==a[i+1]) continue;

        nm[a[i]]=c.size();

        c.pb(a[i]);

    }

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll N=0,M,q,A,B,C;

    map<ll,int> nm;vector<ll> a;vector<int> c;

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

    fr(i,q){

        cin>>d[i];

        a.pb(d[i]);

    }

    a.pb(0);

    sort(a.begin(),a.end());

    cc(a,nm,c);

    SintMIN<int> sg(c.size(),1e9+1);

    fr(i,N){

        sg.ud(nm[-(xst[i].ft-xst[i].sd.ft)],nm[-(xst[i].ft-xst[i].sd.sd)],xst[i].ft);

    }

    fr(i,q){

        ll ans=sg.gt(nm[d[i]]);

        if(ans==1e9+1) cout<<-1<<endl;

        else cout<<ans<<endl;

    }

}