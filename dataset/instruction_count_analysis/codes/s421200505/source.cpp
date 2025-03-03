#include"stdc++.h"

#define model l,mid,num<<1

#define moder mid+1,r,num<<1|1

#define bug(k)  cout<<"text :"<<t<<endl

#define lowbit(k) k&-k

using namespace std;

typedef long long LL;

const LL mod=1e9+7;

const int M=1e5+5;

map <string,int> ma;

int n,x;

int arr[M];

int bits_gcd(int x,int y)

{

    if(y==0)return x;

    if(x==0)return y;

    int i,j;

    for(i=0;0==(x&1);i++)x>>=1;

    for(j=0;0==(y&1);j++)y>>=1;

    if(i>j)i=j;

    while(1)

    {

        if(x<y)x^=y,y^=x,x^=y;

        if(0==(x-=y))return y<<i;

        while(0==(x&1))x>>=1;

    }

}

int main()

{

     int ans;

     int t;

     while(cin>>n>>x)

     {

         ans=INT_MAX;

         for(int i=1;i<=n;++i)

         {

             scanf("%d",&t);

             if(t>x)t^=x,x^=t,t^=x;

             arr[i]=x-t;

         }

         int ans=arr[1];

         for(int i=2;i<=n;++i)

         {

//             cout<<ans<<" "<<arr[i]<<endl;

//             cout<<bits_gcd(ans,arr[i])<<endl;

             ans=bits_gcd(ans,arr[i]);

         }

         cout<<ans<<endl;

     }

}