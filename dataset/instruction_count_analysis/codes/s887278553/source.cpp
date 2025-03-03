#include"stdc++.h"

#define INF 1e9

#define llINF 1e18

#define MOD 1000000007

#define pb push_back

#define mp make_pair 

#define F first

#define S second

#define ll long long

#define vi vector<ll>

#define vvi vector<vi>

#define BITLE(n) (1LL<<((ll)n))

#define SHIFT_LEFT(n) (1LL<<((ll)n))

#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))

#define ALL(a) (a).begin(),(a).end()

using namespace std;



int main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  ll a,b;cin>>a>>b;

  for(ll i=1;i<=1111111;i++){

    if((ll)((double)i*0.08) == a &&

       (ll)((double)i*0.1) == b){

      cout<<i<<endl;

      return 0;

    }

  }

  cout<<-1<<endl;

  return 0;

}
