#include<algorithm>

#include<iostream>

#include<string>

#include<cstdlib>

#include<cstring>

#include<cmath>

using namespace std;

int main(){

  int i;

  int n,m,h,k;

  while(cin>>n>>m>>h>>k&&n+m+h+k){

    int a[1000];

    for(i=0;i<n;i++)

      cin>>a[i];

    pair<int,int> b[100000];

    for(i=0;i<m;i++){

      int p,q;

      cin>>p>>q;

      b[i]=make_pair(q,p);

    }

    sort(b,b+m);

    int c[1000];

    for(i=0;i<n;i++)

      c[i]=i;

    for(i=0;i<m;i++){

      int p;

      p=c[b[i].second-1];

      c[b[i].second-1]=c[b[i].second];

      c[b[i].second]=p;

      b[i]=make_pair(c[b[i].second],c[b[i].second-1]);

    }

    pair<int,int> d[1000];

    for(i=0;i<n;i++)

      d[i]=make_pair(c[i],a[i]);

    sort(d,d+n);

    int sm=0;

    for(i=0;i<k;i++)

      sm+=d[i].second;

    int mn=sm;

    for(i=0;i<m;i++){

      if(b[i].first<k&&b[i].second>=k){

	if(d[b[i].first].second>d[b[i].second].second)

	  mn=min(mn,sm-d[b[i].first].second+d[b[i].second].second);

      }

      if(b[i].first>=k&&b[i].second<k){

	if(d[b[i].first].second<d[b[i].second].second)

	  mn=min(mn,sm+d[b[i].first].second-d[b[i].second].second);

      }

    }

    cout<<mn<<endl;

  }

  return 0;

}