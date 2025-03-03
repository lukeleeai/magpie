#include"stdc++.h"



using namespace std;



#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define endl '\n'

#define Endl '\n'

#define cont continue

#define gcd(a,b) __gcd(a,b)

#define lcm(a,b) a*b/__gcd(a,b)

#define pb push_back

#define mp make_pair

#define mem(x) memset(x, 0, sizeof(x))



const ll inf=1e18;

const int mod=1e9+7;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

const int mxn = 2e5+10;



int main(){

    fast;



    int tt = 1;

    //cin>>tt;

    for(int tc = 1; tc <= tt; tc++) {

        ll n,x,ans = 0,s;

        cin>>n>>x;

        int ip[n];

        for(int i = 0; i < n; i++) cin>>ip[i];

        for(int i = 1; i < n; i++) {

			s = ip[i] + ip[i-1];

			if(s > x) {

				if(ip[i] >= (s-x)) {

					ans += (s-x);

					ip[i] -= (s-x);

				}

				else {

					ans += (s-x);

					s -= ip[i];

					ip[i] = 0;

					ip[i-1] -= (s-x);

				}

			}

		}

		cout<<ans<<endl;

        

        

    }







return 0;

}
