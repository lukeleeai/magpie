//BISMILLAHIR RAHMANIR RAHIM

//RHYTHM_086_NS_01

//ALAN_IS_ON....







#include "stdc++.h"



//define



#define                boost_                         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define                iter_(i,n)                     for (int i = 0; i < int(n); i++)

#define                for_n(i, n)                    for (int i = 1; i <= int(n); i++)

#define                pb                             push_back

#define                mp                             make_pair

#define                itr                            ::iterator

#define                s_sort(s)                      sort(s.begin(),s.end())

#define                n_sort(a)                      sort(a,a+n)

#define                thank_you                      return 0

#define                thanks                         return

#define                pii                            pair<int,int>

#define                precise_impact                 cout<<setprecision(10)<<fixed;



using namespace std;



//data type

typedef long long int ll;

typedef unsigned long long int ulli;

typedef double db;





//constants

#define PI acos(-1.00)

#define MOD 1000000007



ll bigmod(ll a,ll b){

    if(b==0){

        return 1;

    }

    ll tm=bigmod(a,b/2);

    tm=(tm*tm)%MOD;

    if(b%2==1)

        tm=(tm*a)%MOD;

    return tm;



}

int egcd(int a,int b,int &x,int &y){

    if(a==0){

        x=0;

        y=1;

        return b;

    }

    int x1,y1;

    int d=egcd(b%a,a,x1,y1);

    x=y1-(b/a)*x1;

    y=x1;

    return d;

}



void solve();





int main()

{

    boost_;

    precise_impact;

    //freopen("in.txt","r",stdin);

    //freopen("out.txt","w",stdout);

    //Here we go...

    int t=1;

    //cin>>t;

    while(t--)

        solve();



    thank_you;

}





void solve()

{

    int n,m;

    cin>>n>>m;

    if(n==m)

        cout<<"Yes"<<endl;

    else

        cout<<"No"<<endl;





}


