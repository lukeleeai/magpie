#include"stdc++.h"

#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5+200;

int main(){

    ll a[MAXN] = {0};

    ll n;

    cin>>n;

    for(ll i = 0; i < n; i++){

      cin>>a[i];

    }

    ll k = a[0];

    ll sum = 0;

    for(int i= 0; i < n; i++){

      if(i == n -1){

        if(a[i] >= k){

          k = a[i];

        }

        sum+=k;

      }else{

        if(a[i] >= k){

          k = a[i];

        }else{

          sum += k - a[i];

          k = a[i];

        }

      }



    }

    cout<<sum<<endl;

    return 0;

}
