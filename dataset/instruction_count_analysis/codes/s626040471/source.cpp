#include "stdc++.h"



using namespace std;



typedef long long ll;



const int N=2e5+50;

ll n,m,k,arr[N],brr[N];



int solve(ll val){

    int low=1,high=m,mid,x=0;

    while(low<=high){

        mid=low+(high-low)/2;

        if (brr[mid]<=val){

            x=mid;

            low=mid+1;

        }

        else

            high=mid-1;

    }

    return x;

}



int main()

{

    cin>>n>>m>>k;

    for (int i=1;i<=n;i++){

        cin>>arr[i];

        arr[i]+=arr[i-1];

    }

    for (int i=1;i<=m;i++){

        cin>>brr[i];

        brr[i]+=brr[i-1];

    }

    int ans=0;

    for (int i=0;i<=n;i++){

        if (arr[i]>k)

            break;

        ans=max(ans,solve(k-arr[i])+i);

    }

    cout<<ans;



    return 0;

}
