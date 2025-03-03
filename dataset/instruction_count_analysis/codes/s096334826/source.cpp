#include <iostream>

#include "stdc++.h"

#define mod 998244353

typedef long long ll;



using namespace std;



void Fastio(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

}



ll fact[1000006], inv[1000006];



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



void calcFacAndInv(ll n)

{

    fact[0] = inv[0] = 1;

    for (ll i = 1; i <= n; i++)

    {

        fact[i] = (i * fact[i - 1]) ;

        inv[i] = fp(fact[i], mod - 2);

    }

}



ll ncr(ll n, ll r)

{

    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;

}



ll npr(ll n, ll r)

{

    return (fact[n] * inv[n - r]) % mod;

}



long double  NCR(int n, int m){

    long double res = 1;

    m = min(m, n - m);

    for(int i = 0; i < m; i++){

        res = res * ( n - i) / (i + 1);

 }

    return res;

}

ll tol(string a){

    ll res=0;

    while(a[0]=='0'){

        a.erase(a.begin());

    }

    if(a=="")a="0";

    for(int i=0; i<a.size(); i++){

        res*=10; res+=a[i]-'0';

    }

    return res;

}

int check(string a, string b){

    for(int i=0; i<a.size(); i++){

        if(a[i]>b[i])return 1;

        if(b[i]>a[i])return -1;

    }

    return 0;

}

class data{

public:

    ll v,d,p;

    data(){}

    data(ll vv, ll dd, ll pp){

        v=vv;  d=dd; p=pp;

    }

};



int primeFactors(int n)

{

    ll c=0;

    while (n % 2 == 0)

    {

        c++;

        n = n/2;

    }

    for (int i = 3; i*i <= n; i = i + 2)

    {

        while (n % i == 0)

        {

            c++;

            n = n/i;

        }

    }

    if (n > 2)

        c++;

    return c;

}

int n,m, counter;

vector<int>arr[200005];

int vis[200005];

void dfs(int node){

    vis[node]=1; counter++;

    for(int i=0; i<arr[node].size(); i++){

        if(!vis[arr[node][i]])dfs(arr[node][i]);

    }

}

int main()

{

    Fastio();

    double n,k,pos=0; cin>>n>>k; k--;

    for(int i=0; i<n; i++){

        int x; cin>>x;

        if(x==1)pos=i;

    }

    ll tmp1, tmp2;

    int p=pos,kk=k;

    while(p%kk && p+1<n)p++;

    pos=p; tmp1=ceil(pos/k);

    tmp2=ceil((n-pos-1)/k);

    ll res=tmp1+tmp2;

    cout<<res<<'\n';



    return 0;

}


