#include"stdc++.h"

using namespace std;

#define ll long long int

#define ull unsigned long long int

#define pb push_back

#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define mem(ara,n) memset(ara,n,sizeof(ara))

#define memb(ara) memset(ara,false,sizeof(ara))

#define all(x) (x).begin(),(x).end()

#define fr freopen("input.txt","r",stdin);

#define fw freopen("output.txt","w",stdout);

const double PI  =3.141592653589793238463;





int main()

{

    faster;

    ll a,b,c,d,e,f=0,ans=0,sum=0,m,n,p,q,r,t,w,x,y,z;

    string s;

    cin>>a>>b>>x;

    if(a==0){

        ans=(b/x)+1;

    cout<<ans<<endl;

    }

    else{

        m=(b/x);

        n=(a-1)/x;

        ans=m-n;

        cout<<ans<<endl;

    }

    return 0;

}










