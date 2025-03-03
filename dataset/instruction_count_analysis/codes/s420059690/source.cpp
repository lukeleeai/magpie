#include "stdc++.h"



#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define all(x) (x).begin(), (x).end()

#define ll long long

#define ii pair<int,int>

#define vi vector<int>

#define vll vector<ll>

#define vii vector<ii>



const int INF = 0x3f3f3f3f;

const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 45+10;

const int mod = 1e9+7;



using namespace std;



int32_t main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    int n,x,s=0;



    cin >> n >> x;



    vi v(n);



    for(int &d:v){

    	cin >> d;

    	s+=d;

    }



    sort(all(v));



    x-=s;



    cout << (n + (x/v[0])) << endl;



    return 0;

}


