#include <iostream>

#include <algorithm>

#include <cmath>

#include <string>

#include <vector>

#include <map>

#include <set>

#include <random>

#include <queue>

#include <stack>

#include <bitset>

#include <cassert>

#define int long long

#define double long double

#define rep(i,n) for(int i=0;i<n;i++)

#define srep(i,n,m) for(int i=n;i<m;i++)

#define elif else if

#define pi 3.141592653589793

#define prique priority_queue

constexpr auto mod=1000000007;

using namespace std;

int gcd(int a,int b){

    if(b==0) return a;

    return gcd(b,a%b);

}

int lcm(int a,int b){

    return a*b/gcd(a,b);

}

bool prime(int n){

    int cnt=0;

    for(int i=1;i<=sqrt(n);i++){

        if(n%1==0)cnt++;

    }

    if(cnt!=1) return false;

    else return n!=1;

}

struct UnionFind{

    vector<int> r;

    UnionFind(int N){

        r=vector<int>(N,-1);

    }

    int root(int x){

        if(r[x]<0) return x;

        return r[x]=root(r[x]);

    }

    bool unite(int x,int y){

        x=root(x);

        y=root(y);

        if(x==y) return false;

        if(r[x]>r[y]) swap(x,y);

        r[x]+=r[y];

        r[y]=x;

        return true;

    }

    int size(int x){

        return -r[root(x)];

    }

};

vector<int> v;

int n,m,cnt=0,ans=0,aa[220000],ab[220000];

pair<int,int> pp[220000];

string s,ss[220000];

queue<int> que;

signed main(){

    cin>>n>>m;

    cout<<abs(n-2)*abs(m-2);

}