#include "stdc++.h"

#define rep(i,n) for(long long i=0; i<n; i++)

#define Rep(i,n) for(long long i=1; i<n; i++)

#define ll long long

#include <math.h>

#include <cmath>

#include <iomanip>

#include <iostream>

#include <numeric>

#include <queue>

#include <set>

#include <vector>





using namespace std;

#define PI acos(-1)

using P =pair<ll,ll>;



ll ketasu(ll a){

   ll num=1;

   while(a/10){

       num++;

       a/=10;

   }

   return num;

}



ll gcd(ll a,ll b){return b ? gcd(b,a%b) :a;}

ll lcm(ll a,ll b){return a*b/gcd(a,b);}



ll kosuu(ll a){

    ll sum=0;

    for(ll i=1;i*i<=a;i++){

        if(a%i==0){

            if(a!=1&&i*i!=a){

            sum+=2;

            }else{

             sum++;   

            }

        }

    }

    return sum;

}













ll di[]={1,0,-1,0};

ll dj[]={0,-1,0,1};



struct UnionFind {

    vector<int>d;

    UnionFind(int n=0):d(n,-1){}

    int find(int x){

        if((d[x])<0)return x;

        return d[x]=find(d[x]);

    }

    bool unite(int x,int y){

        x =find(x);y=find(y);

        if(x==y)return false;

        if(d[x]>d[y])swap(x,y);

        d[x]+=d[y];

        d[y]=x;

        return true;

    }

    bool same(int x,int y){return find(x)==find(y);};

    int size(int x){return -d[find(x)];};

};



int deg[100005];

vector<int> to[100005];





ll n,m,q;

vector<ll>a,b,c,d;

ll ans;



void dfs(vector<ll> A){

    if(A.size()==n+1){

        ll sum=0;

        rep(i,q){

            if(A[b[i]]-A[a[i]]==c[i])sum+=d[i];

        }

        ans=max(ans,sum);

        return;

    }

    

    A.push_back(A.back());

    while(A.back()<=m){

        dfs(A);

        A.back()++;

    }

}



// auto mod int

// https://youtu.be/L8grWxBlIZ4?t=9858

// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize

// https://youtu.be/8uowVvQ_-Mo?t=1329 : division

const int mod = 1000000007;

struct mint {

  ll x; // typedef long long ll;

  mint(ll x=0):x((x%mod+mod)%mod){}

  mint operator-() const { return mint(-x);}

  mint& operator+=(const mint a) {

    if ((x += a.x) >= mod) x -= mod;

    return *this;

  }

  mint& operator-=(const mint a) {

    if ((x += mod-a.x) >= mod) x -= mod;

    return *this;

  }

  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}

  mint operator+(const mint a) const { return mint(*this) += a;}

  mint operator-(const mint a) const { return mint(*this) -= a;}

  mint operator*(const mint a) const { return mint(*this) *= a;}

  mint pow(ll t) const {

    if (!t) return 1;

    mint a = pow(t>>1);

    a *= a;

    if (t&1) a *= *this;

    return a;

  }



  // for prime mod

  mint inv() const { return pow(mod-2);}

  mint& operator/=(const mint a) { return *this *= a.inv();}

  mint operator/(const mint a) const { return mint(*this) /= a;}

};

istream& operator>>(istream& is, mint& a) { return is >> a.x;}

ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}



mint f(int n) {

    if(n==0)return 1;

    mint x=f(2/n);

    x*=x;

    if(n%2==1)x*=2;

    return x;

}



mint choose(int n,int a){

    mint x =1,y=1;

    rep(i,a){

      x*=n-i;

      y*=a+i;

    }

    return x/y;

}



int main()

{

  ll n,m,k;

  cin>>n>>m>>k;

  vector<ll>a(n);

  vector<ll>b(m);

  rep(i,n)cin>>a[i];

  rep(i,m)cin>>b[i];

  vector<ll>A(n+1);

  vector<ll>B(m+1);

  A[0]=0;

  B[0]=0;

  Rep(i,n+1)A[i]=A[i-1]+a[i-1];

  Rep(i,m+1)B[i]=B[i-1]+b[i-1];

  ll ans=0;

  ll j=m;

  rep(i,n+1){

      ll sum=A[i];

      if(k<sum)break;

      while(k<sum+B[j]){

          j--;

      }

      ans=max(ans,i+j);

  }

  cout<<ans<<endl;

}

 




