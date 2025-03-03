#include "stdc++.h"

#include <iostream>

#include <set>

#include <vector>

#include <algorithm>



#define fr(i,b,e) for(int i=(b); i<(e); ++i)

#define rp(i,e) for(int i=0; i<(e); ++i)

#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long int li;

typedef long long ll;

const int INF=1000000;



vector<int> a(1e6);

vector<ll> cnt(1e6);



int main(void){

    int n;

    cin >> n;

    rp(i,n){

        cin >> a[i];

        ++cnt[a[i]-1];

    }



    ll sum=0;

    

    rp(i,n){

        sum+=cnt[i]*(cnt[i]-1);

    }



    sum=sum>>1;



    rp(i,n){

        cout << sum-cnt[a[i]-1]+1 << '\n';

    }

}