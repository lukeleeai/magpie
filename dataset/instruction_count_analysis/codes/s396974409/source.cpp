#include"stdc++.h"

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

#define pi 3.141592653589793238

#define int long long

using namespace __gnu_pbds;

using namespace std;

template <typename T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());

// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



long long power(long long a, long long b,long long m) {

    long long res = 1;

    while (b > 0) {

        if (b & 1)

            res = res * a %m;

        a = a * a %m;

        b >>= 1;

    }

    return res;

}





signed main()

{

ios_base::sync_with_stdio(false);

cin.tie(NULL);  

cout.tie(0);   



#ifndef ONLINE_JUDGE

    if(fopen("INPUT.txt","r"))

    {

    freopen ("INPUT.txt" , "r" , stdin);

    freopen ("OUTPUT.txt" , "w" , stdout);

    }

#endif  



    int n,m,k;

    cin>>n>>m>>k;

    int x,y;

    cin>>x>>y;

    string s,t;

    cin>>s>>t;

    int xx=0;

    for(int i=0;i<k;i++)

    {

        if(s[i]=='L')

            xx++;

        if(xx>=y)

        {

            cout<<"NO";

            return 0;

        }

        if(t[i]=='R')

        {

            if(xx<=0)

            {

                if(abs(xx)+y+1>m)

                    continue;

            }

                xx--;

        }

    }

    xx=0;

    for(int i=0;i<k;i++)

    {

        if(s[i]=='R')

            xx++;

        if(xx+y>m)

        {

            cout<<"NO";

            return 0;

        }

        if(t[i]=='L')

        {

            if(xx<=0)

            {

                if(abs(xx)+1>=y)

                    continue;

            }

                xx--;

        }

    }

    xx=0;

    for(int i=0;i<k;i++)

    {

        if(s[i]=='U')

            xx++;

        if(xx>=x)

        {

            cout<<"NO";

            return 0;

        }

        if(t[i]=='D')

        {

            if(xx<=0)

            {

                if(abs(xx)+x+1>n)

                    continue;

            }

                xx--;

        }

    }

    xx=0;

    for(int i=0;i<k;i++)

    {

        if(s[i]=='D')

            xx++;

        if(xx+x>n)

        {

            cout<<"NO";

            return 0;

        }

        if(t[i]=='U')

        {

            if(xx<=0)

            {

                if(abs(xx)+1>=x)

                    continue;

            }

                xx--;

        }

    }

    cout<<"YES";



} 

    
