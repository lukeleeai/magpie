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

const int M=1004;

vector<string>s4=

{

 "aabc",

 "ddbc",

 "bcaa",

 "bcdd"

};

vector<string>s5=

{

  "..abc",

  "..abc",

  "ddeef",

  "ggh.f",

  "iihjj"

};

vector<string>s6=

{

    "...abc",

    "...abc",

    "ddee.f",

    "..gghf",

    "iij.h.",

    "kkj.ll"

};

vector<string>s7=

{

    "....abc",

    "....abc",

    "....def",

    "....def",

    "gghh..i",

    "jjkk..i",

    "llmmnn."

};

vector<vector<string > >ok={s4,s4,s4,s4,s4,s5,s6,s7};

 main()



{

    fast

    int n;

    cin>>n;

    if(n<=2)

    {

        cout<<"-1"<<endl;

        return 0;

    }

    if(n==3)

    {

        cout<<"aa."<<endl;

        cout<<"..a"<<endl;

        cout<<"..a"<<endl;

        return 0;

    }

    vector<string>ses(n,string(n,'.'));

    int x=n;

    int z=0;

    while(x>7)

    {

        f(i,0,3)

        {

            f(j,0,3)

            {

                ses[z+i][z+j]=s4[i][j];

            }

        }

        z+=4;

        x-=4;

    }

    f(i,0,x-1)

    {

        f(j,0,x-1)

        {

            ses[z+i][z+j]=ok[x][i][j];

        }

    }

    f(i,0,n-1)

    {

        cout<<ses[i]<<"\n";

    }

    return 0;



}






































































