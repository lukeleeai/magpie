#include<iostream>

#include<string.h>

#include<cstdio>

#include<algorithm>

#include<stack>

#include<queue>

#include<vector>

#include<cmath>

#include<utility>

#define ll long long int

#define ld long double

#define INF 1000000000

#define EPS 0.0000000001

#define rep(i,n) for(i=0;i<n;i++)

using namespace std;

typedef pair<int, int> P;



string str;



int main()

{

  int n,i;

  int a[1000000];

  bool p[1000000];





  cin>>n;

  p[0]=false;



  for(i=1;i<=n;i++){

    cin>>a[i];

    p[i]=false;

  }



  for(i=1;i<=n;i++){

    if(a[a[i]]==i){

      p[i]=true;

      p[a[i]]=true;

    }

  }

  int ans=0;

  for(i=1;i<=n;i++)

    if(p[i])

      ans++;

  cout<<ans/2<<endl;

}
