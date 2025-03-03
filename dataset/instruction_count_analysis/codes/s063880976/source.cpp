#include "stdc++.h"

//freopen("transmitters.in","r",stdin);

//cout<<fixed<<setprecision(6)<<n<<endl;

// transform(s.begin(), s.end(), s.begin(), ::tolower);

//double PI=3.14159265359,c=0;

#define all(v) v.begin(),v.end()

#define endl '\n'

#define ll long long

//#define f(n) for(int i=;i<n;i++)

double PI = acos(-1);

using namespace std;

void fast()

{

    std::ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

}

ll arr[10000000],n;

vector<ll>v(1e6,-1);

ll minCost(int indx)

{

    ll path1,path2;

    if(indx==n-1)

        return 0;

        

    if(v[indx]!=-1)

        return v[indx];

        

    if(indx+1<n)

        path1=abs(arr[indx]-arr[indx+1])+minCost(indx+1);



    if(indx+2<n)

        path2=abs(arr[indx]-arr[indx+2])+minCost(indx+2);



    return v[indx]=min(path1,path2);

}

int main()

{

    fast();

    cin>>n;

    for(int i=0; i<n; i++)

        cin>>arr[i];



    cout<<minCost(0)<<endl;



    return 0;

}
