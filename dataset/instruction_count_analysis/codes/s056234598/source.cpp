///Bismillahir Rahmanir Rahim

#include "bits/stdc++.h"



#define                           ll                          long long

#define                           int                         ll

#define                           fi                          first

#define                           si                          second

#define                           mp                          make_pair

#define                           pb                          push_back

#define                           pi                          pair<ll,ll>

#define                           clr(x)                      memset(x,0,sizeof(x));

#define                           f(i,l,r)                    for(int i=l;i<=r;i++)

#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)

#define                           done(i)                     cout<<"done = "<<i<<endl;

#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;

#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



using namespace std;



const ll inf=1e18;

const int mod=1e9+7;

const int M=100005;



 main()



{

    fast

    int n;

    cin>>n;

    f(i,1,9)

    {

        f(j,1,9)

        {

            if(i*j==n)

            {

                cout<<"Yes"<<endl;

                return  0;

            }

        }

    }

    cout<<"No"<<endl;

    return 0;



}






































































