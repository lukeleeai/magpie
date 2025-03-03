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

#define Max(a) (*max_element(ALL(a)))

#define Min(a) (*min_element(ALL(a)))

using namespace std;



int main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  ll a,b;cin>>a>>b;

  for(ll i=1;i<=111111;i++){

    if(i*8/100 == a && i*10/100 == b){

      cout<<i<<endl;

      return 0;

    }

  }

  cout<<-1<<endl;

  return 0;

}