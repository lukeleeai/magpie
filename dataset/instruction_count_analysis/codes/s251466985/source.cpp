

#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N=1e6+10;

int n,mod=1e9+7;

ll arr[N],arr2[N];

bool found[N]={};

ll fp(ll base, ll exp)

{

    if (exp == 0)

        return 1;

    ll ans = fp(base, exp / 2);

    ans = (ans * ans) % mod;

    if (exp % 2 != 0)

        ans = (ans * (base % mod)) % mod;

    return ans;

}





int main()

{

    ll cnt[1000]= {};

    bool primes[1005];

    int n = 1000;

    memset(primes, true, sizeof primes);

    for(int i = 2; i*i <= n; i++)

    {

        if(primes[i])

        {

            for(int j = i*i; j <= n; j += i)

                primes[j] = false;

        }

    }

    vector<int>v;

    ll ans=1,aa;

    cin>>aa;

    for(int i=0; i<aa; i++)

    {

        cin>>arr[i];

        arr2[i]=arr[i];

    }



    for(int i = 2; i <= n; i++)

    {

        if(primes[i])

            v.push_back(i);

    }

//cout<<v.size();

    ll lcm=1;

    for(int i=0; i<v.size(); i++)

    {

        for(int j=0; j<aa; j++)

        {

            ll k=0;

            while(arr[j]%v[i]==0)

            {

                found[arr[j]]=1;

                k++;

                arr[j]/=v[i];

            }

            cnt[i]=max(k,cnt[i]);

        }



        lcm*=fp(v[i],cnt[i]);

        lcm%=mod;



    }

    for(int i=0;i<aa;i++){

        if(!found[arr[i]]){

            lcm*=arr[i];

            found[arr[i]]=1;

            lcm%=mod;

        }

    }

    //cout<<lcm<<endl;



    ll answer=0;



    for(int i=0; i<aa; i++)

    {

        answer+=(lcm*fp(arr2[i],mod-2))%mod;

        answer%=mod;

        //ans%=mod;

    }

    cout<<answer;

    return 0;

}
