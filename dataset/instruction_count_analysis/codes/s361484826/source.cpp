#include"stdc++.h"

using namespace std;



#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl            "\n"

#define sq(x)           ((x)*(x))

#define pi              acos(-1.0)

#define NUM             1000005



typedef long long ll;





int main()

{

    FastRead



    ll n,cnt=0;

    

    cin>>n;

    

    vector<ll>v(n);

    

    for(ll i=0;i<n;i++)

    {

        cin>>v[i];

        

        if(v[i]%2)

            cnt++;

    }

    

    if(cnt%2)

        cout<<"NO"<<endl;

    else

        cout<<"YES"<<endl;

}
