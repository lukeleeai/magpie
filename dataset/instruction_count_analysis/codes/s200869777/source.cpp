#include"stdc++.h"

using namespace std;

typedef int Int;

#define int long long

#define INF 0x3f3f3f3f

int gcd(int a,int b)

{

    return b==0?a:gcd(b,a%b);

}

int lcm(int a,int b)

{



}

Int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int n;

    cin>>n;

    cout<<2*n/gcd(2,n)<<endl;

    return 0;

}