#include<iostream>

#include<string.h>

#include<string>

#include<cstdio>

#include<algorithm>

#include<stack>

#include<queue>

#include<vector>

#include<cmath>

#include<utility>

#include<set>

#define ll long long int

#define ld long double

#define INF 1000000000

#define EPS 0.0000000001

#define MOD 1000000007

#define rep(i,n) for(i=0;i<n;i++)

using namespace std;

typedef pair<int, int> pii;



int main()

{

  int n;

  ll t[100000];

  ll a[100000];

  pii tr[100000];//t range

  pii ar[100000];//a range

  int i,j;

  ll ans=1LL;



  cin>>n;



  cin>>t[0];

  tr[0].first=tr[0].second=t[0];



  for(i=1;i<n;i++){

    cin>>t[i];

    tr[i].second=t[i];

    if(t[i]>t[i-1])

      tr[i].first=t[i];

    else

      tr[i].first=1;

  }



  rep(i,n){

    cin>>a[i];

    ar[i].second=a[i];

  }



  ar[n-1].first=ar[n-1].second=a[n-1];

  for(i=n-2;i>=0;i--)

    if(a[i]>a[i+1])

      ar[i].first=a[i];

    else

      ar[i].first=1;



  rep(i,n){

    if(ar[i].first<=tr[i].first && tr[i].second<=ar[i].second)//a-t-t-a

      ans=(ans*(tr[i].second-tr[i].first+1))%MOD;

    else if(tr[i].first<=ar[i].first && ar[i].second<=tr[i].second)//t-a-a-t

      ans=(ans*(ar[i].second-ar[i].first+1))%MOD;

    else if(ar[i].first<=tr[i].first && tr[i].first<=ar[i].second)//a-t-a-t

      ans=(ans*(ar[i].second-tr[i].first+1))%MOD;

    else if(tr[i].first<=ar[i].first && ar[i].first<=tr[i].second)//t-a-t-a

      ans=(ans*(tr[i].second-ar[i].first+1))%MOD;

    else{

      cout<<"0"<<endl;

      return 0;

    }

  }

  cout<<ans<<endl;

}


