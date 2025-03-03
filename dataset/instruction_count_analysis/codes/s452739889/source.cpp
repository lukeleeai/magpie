//

// author  : Abhishek

//

#include "stdc++.h"



#define ll long long

#define db double

#define deb(x) cout<<#x<<": "<<x<<"\n"

#define all(x) x.begin(),x.end()

#define fo(i, n) for(i=0 ; i<n ; i++)

#define Fo(i, k, n) for(i=k ; i<n ; i++)



using namespace std;



const ll mod = 1000000007;

const ll N = 300005;  // array size

const ll inf = 10000000000000000;





void print(vector<ll> v) {

    ll i;

    fo(i, v.size())cout << v[i] << " ";

    cout << "\n";

}



vector<ll> read(ll n) {

    ll i;

    vector<ll> arr(n, 0);

    fo(i, n)cin >> arr[i];

    return arr;

}



vector<ll> read(ll n, ll k) {

    ll i;

    vector<ll> arr(n + k, 0);

    Fo(i, k, n + k)cin >> arr[i];

    return arr;

}



bool isEven(ll n) {

    return n % 2 == 0;

}



bool isOdd(ll n) {

    return n % 2 != 0;

}





void solve() {

    ll t;

    cin >> (t);

    while (t--) {



        ll i, j, k, n, m, p, q, x, y, a, b, l, r;





    }

}



int main() {



//#ifndef ONLINE_JUDGE

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//#endif



    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    ll i, j, k, n, m, p, q, x, y, a, b, l, r;





    cin>>n;



    Fo(i,1,10){

        Fo(j,1,10){

            if(i*j == n){

                cout<<"Yes\n";

                return 0;

            }

        }

    }



    cout<<"No\n";



    return 0;

}




