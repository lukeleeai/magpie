#include<iostream>

#include<cstdlib> 

#include<sstream>

#include<cstdio>

#include<stack>

#include<cstdio>

#include<map>

#include<set>

#include<queue>

#include<cstring>

#include<cmath>

#include<vector>

#include<algorithm>

using namespace std;

typedef long long LL;

#define me(a,b) memset(a,b,sizeof(a))

#define inf 0x3f3f3f3f

const int N=1111122;

const int M=200005;

int main()

{

    std::ios::sync_with_stdio(false);

    int n,i,j,m;

    cin>>n;

    int ans=0;

    int a[M];

    int maxx=0;

    for(i=0;i<n;i++)

    {

        cin>>a[i];

        maxx=max(maxx,a[i]);

        ans+=a[i];

    }

    if(maxx<ans-maxx)cout<<"Yes"<<endl;

    else cout<<"No"<<endl;

    //system("pause");

    return 0;

}