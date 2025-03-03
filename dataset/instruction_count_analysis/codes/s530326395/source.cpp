#include"stdc++.h"

using namespace std;

#define ll long long

int main(){

    ll n, k;

    cin >> n >> k;

    ll p = n % k;

    cout << min(p, k - p) << endl;

    return 0;

}