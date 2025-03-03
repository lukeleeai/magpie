#include "stdc++.h"

using namespace std;



#define ll long long



int main() {

    ll n,count=0,k;

    cin>>n>>k;

    while(n!=0)

    {

        count++;

        n=n/k;

    }

    cout<<count;

    return 0;

}