#include <iostream>

#include<cstdlib>

#include<queue>

#include<set>

#include<vector>

#include<string>

#include<cmath>

#include<algorithm>

#include<stack>

#include<map>

#include<deque>

#include<cstdio>

#include<cstdio>

#include<time.h>

using namespace std;

#define rep(i,a) for(int i=0;i<a;i++)

#define pd(a,n) for(int i=0;i<n;i++)cout<<a[i]<<((i==n-1)?"\n":" ")

#define pdd(a,n,m)for(int i=0;i<m;i++)pd(a,m)

#define mp make_pair

#define pb push_back

#define ll __int64

#define __int64 long long

#define P pair<int,int>

#define PP pair<P,int>



int n;

string s[222222];

map<string,int> ta;



int main(){

  cin>>n;

  rep(i,n)cin>>s[i];

  rep(i,n)ta[s[i]]++;

  int ma=-1;



  rep(i,n){

    ma=max(ma,ta[s[i]]);

  }

  sort(s,s+n);

  rep(i,n){

    if(ma==ta[s[i]]){

      cout<<s[i]<<endl;

      i+=(ta[s[i]]-1);

    }

  }



  return 0;

}
