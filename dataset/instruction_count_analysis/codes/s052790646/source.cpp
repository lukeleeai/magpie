// /*

// power code taken from geeks for geeks

// */



#include "stdc++.h"

#define MODD 1000000007LL

#define MAX_SIZE 100000000

#define MAX_N 200001

using namespace std;

typedef long long ll;

typedef long double ld;



ll max(ll a,ll b){return a>b?a:b;}

ll min(ll a,ll b){return a<b?a:b;}

double max(double a,double b){return a>b?a:b;}

double min(double a,double b){return a<b?a:b;}



ll modd(ll a){if(a<0LL) return a*-1LL;return a;}

double modd(double a){if(a<0.0) return a*-1.0;return a;}



ll modulo(ll a){return a % MODD; }



ll power(ll k, ll p){

    if (p == 0)

        return 1LL;

 

    ll P = power(k, p/2LL);

    P = (P * P) % MODD;

 

    if (p % 2 == 1)

        P = (P * k) % MODD;

 

    return P;

}





struct p_str{

    ll a,b,c;

};





void swap(ll& s1, ll &s2){

    ll temp=s1;

    s1=s2;

    s2=temp;

}

ll gcd(ll a, ll b){

    if(b==0){

        return a;

    }

    return gcd(b, a%b);

}



void solve(){

    ll k;

    cin>>k;

    ll a, b;

    cin>>a>>b;

    ll i=a;

    while(i<=b){

        if(i%k==0){

            cout<<"OK"<<endl;

            return;

        }

        i++;

    }

    cout<<"NG"<<endl;

}





int main(){





    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    ll t=1;



    // cin>>t;

    

    while(t--){

        solve();

    }

    return 0;

}
