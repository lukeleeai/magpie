#pragma GCC optimize("Ofast")

#include<iostream>

#include<string>



using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)



int a[200000];



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int n;cin>>n;

    REP(i,n)cin>>a[i];

    int b=0;REP(i,n)b^=a[i];

    REP(i,n){cout<<(a[i]^b)<<"\n";}

    return 0;

}