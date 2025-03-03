/* ~ CoderMehraJ ~ */

#include "stdc++.h"

using namespace std;



#define show(x) cout << #x << " = " << x << '\n';



long long hehe(int a){

    if(a<2) return 0;

    long long b;

    if(a%2) {

        b=((a-1)/2);

        b*=a;

    }

    else {

        b=(a/2);

        b*=(a-1);

    }

    return b;

}



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int n;

    cin>>n;

    int ar[n];

    map < int , int > mp;

    map < int , long long > ans;

    unsigned long long anss;

    for(int i=0;i<n;i++) {

        cin>>ar[i];

        mp[ar[i]]++;

    }

    for(auto x: mp) anss+=hehe(x.second);

        

    for(int i=0;i<n;i++){

        cout<<anss-hehe(mp[ar[i]])+hehe(mp[ar[i]]-1)<<"\n";

    }

    return 0;

}

//fixed<<setprecision(1)
