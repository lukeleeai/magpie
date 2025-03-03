#include"stdc++.h"

using namespace std;

int n;

vector<int>v,v2;

bool check(int x){

    v2.clear();

    for(int i=0;i<2*n-1;i++)v2.push_back(v[i]>=x);

    if(v[n-1]>=x&&v[n-2]>=x)return 1;

    if(v[n-1]>=x&&v[n]>=x)return 1;

    if(v[n-1]<x&&v[n-2]<x)return 0;

    if(v[n-1]<x&&v[n]<x)return 0;

    int l=n-2,r=n;

    while(l>0&&v2[l]!=v2[l-1])l--;

    while(r<2*n-2&&v2[r]!=v2[r+1])r++;

    if(r-l==2*n-2)return v2[l]; 

    if((r-l+1)%2)return v2[l];//ÏàÍ¬ 

    if(n-1-l<r-n+1)return v2[l];//ÀëµÃ¸ü¶Ì 

    return v2[r];

}

int main(){

    cin>>n;

    for(int i=0;i<2*n-1;i++){

        int a;

        cin>>a;

        v.push_back(a);

    }

    int l=1,r=2*n-1;

    while(l<r){

        int mid=(l+r+1)/2;

        if(check(mid))

            l=mid;

        else

            r=mid-1;

        //cout<<l<<' '<<r<<endl;

    }

    cout<<l;

}