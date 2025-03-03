#include"stdc++.h"

using namespace std;

inline int minn(int a,int b)

{

    if(a>b)return b;

    else return a;

}

int main()

{

    long long int n,m,ans;

    cin>>n>>m;

    if(n>=m/2)ans=m/2;

    else ans=(n*2+m)/4;

    cout<<ans<<endl;

    return 0;

}