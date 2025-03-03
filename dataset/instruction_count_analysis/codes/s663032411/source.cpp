#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp>

#define sz(v)   ((int)(v).size())

#define  all(v)    ((v).begin()),((v).end())

#define  allr(v)    ((v).rbegin()),((v).rend())

#define   pb         push_back

#define   mp         make_pair

#define    Lcm(a,b)  ((a*b)/(__gcd(a,b)))

#define    clr(v,d)      memset( v, d ,sizeof(v))

#define    PI            acos(-1)

typedef  long long     ll ;

typedef  unsigned long long     ull ;

const long double eps= (1e-9);

using namespace std;

using namespace __gnu_pbds;

int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}

int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}

int setBit1(ll num, ll idx) {return num | (1ll<<idx);}

ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}

ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const ll N=200000+9,mod=1e9+7;

set< pair<ll,ll> > st;

map< pair<ll,ll>,ll> mb;

ll P[N];

pair<ll,ll> get_slope(ll a,ll b){



  ll gg=__gcd(llabs(a),llabs(b));

  a/=gg;

  b/=gg;



  if((a<0&&b>=0)||(b<0&&a>=0)){

    b=llabs(b);

    a=llabs(a)*-1;

  }

  else{

    b=llabs(b);

    a=llabs(a);

  }



  return mp(a,b);

}

int main(){

    GO();

    int n;

    cin>>n;

    ll cnt=0,cnt1=0,cnt2=0;

    P[0]=1;

    for(int i=1;i<N;i++) P[i]=(P[i-1]*2)%mod;



    for(int i=0;i<n;i++){

        ll a,b;

        cin>>a>>b;

        if(a==0&&b==0){

            cnt++;

            continue;

        }

        if(a==0){

           cnt1++;

           continue;

        }

        if(b==0){

            cnt2++;

            continue;

        }

        pair<ll,ll> p=get_slope(a,b);

        mb[p]++;

     //   cout<<p.first<<" "<<p.second<<endl;

        if(llabs(p.first)>p.second){

            swap(p.first,p.second);

            if(p.second<0) p.second*=-1,p.first*=-1;

        }



        st.insert(mp(llabs(p.first),p.second));

    }



    ll ans=1;

    for(auto it=st.begin();it!=st.end();it++){

        ll f=(*it).first;

        ll s=(*it).second;







       // cout<<f<<" "<<s<<"\n";

        ll fadd=0;

        for(int j=0;j<(1<<4)&&f!=s;j++){



            if((getBit(j,0)&&getBit(j,3))||(getBit(j,1)&&getBit(j,2))) continue;

            ll add=1;

            bool ok=1;

            for(int k=0;k<4;k++){



                if(getBit(j,k)==0) continue;



                pair<ll,ll> pp=(*it);



                if(k==1) pp.first*=-1;

                if(k==2) swap(pp.first,pp.second);

                if(k==3) swap(pp.first,pp.second),pp.first*=-1;

                if(mb[pp]==0){

                    ok=0;

                    break;

                }



                add*= (((P[mb[pp]]-1)%mod+mod)%mod);

                add%=mod;

            }

            if(ok==0){

                continue;

            }

            fadd+=add;

            fadd%=mod;

        }



        for(int j=0;j<(1<<2)&&f==s;j++){



            ll add=1;

            bool ok=1;

            if(getBit(j,0)&&getBit(j,1)) continue;

            for(int k=0;k<2;k++){



                if(getBit(j,k)==0) continue;



                pair<ll,ll> pp=(*it);



                if(k==1) pp.first*=-1;



                if(mb[pp]==0){

                    ok=0;

                    break;

                }



                add*= (((P[mb[pp]]-1)%mod+mod)%mod);

                add%=mod;

            }

            if(ok==0){

                continue;

            }

            fadd+=add;

            fadd%=mod;

        }

       // cout<<f<<" "<<s<<" "<<fadd<<endl;

        ans*=(fadd);

        ans%=mod;



    }



    ll fres=((ans-1)%mod+mod)%mod;

    ll ffres=fres;

  //  cout<<fres<<endl;

    if(cnt>0){

        fres+= (cnt)%mod;

        fres%=mod;

    }

  //  cout<<fres<<endl;

    ll nfres=0;

    if(cnt1>0){

        nfres+= ((ffres+1)%mod*(((P[cnt1]-1)%mod+mod)%mod))%mod;

        nfres%=mod;

    }

    if(cnt2>0){

        nfres+= ((ffres+1)%mod*(((P[cnt2]-1)%mod+mod)%mod))%mod;

        nfres%=mod;

    }

    cout<<(fres+nfres)%mod<<"\n";

}

/*

8

1 1

-1 1

0 0

0 1

0 0

0 0

1 0

2 0



Cres=17

*/












































