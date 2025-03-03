#include"stdc++.h"

#define ll long long

#define maxn 100005

#define lson l,mid,rt<<1

#define rson mid+1,r,rt<<1|1

#define pb push_back

#define pii pair<int,int>

using namespace std;



int n,k;

int a[5005];



bool Check(int mid){

    if(a[mid]>=k) return 1;

    bitset<5005> bs;

    bs[0]=1;

    for(int i=1;i<=n;i++){

        if(a[i]>5000) break;

        if(i!=mid) {

            bs|=bs<<a[i];

        }

    }

    for(int i=k-1;i>=k-a[mid];i--){

        if(bs[i]) return 1;

    }

    return 0;

}



int main(){



    cin>>n>>k;

    for(int i=1;i<=n;i++){

        cin>>a[i];

    }

    sort(a+1,a+n+1);

    int L=1,R=n,mid;

    while(L<=R){

        mid=L+R>>1;

        if(Check(mid)) R=mid-1;

        else L=mid+1;

    }

    cout<<R<<endl;





}




