#include<vector>

#include<algorithm>

#include<iostream>

#include<string>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<cmath>

using namespace std;

int main(){

  int i,j;

  int d,m,n,p;

  int sm;

  vector<int> a;

  while(cin>>d&&d){

    cin>>m>>n;

    a.clear();

    a.push_back(0);

    for(i=0;i<m-1;i++){

      int c;

      cin>>c;

      a.push_back(c);

    }

    a.push_back(d);

    sort(a.begin(),a.end());

    sm=0;

    for(i=0;i<n;i++){

      cin>>p;

      for(j=0;;j++){

	if(a[j]<=p&&p<a[j+1])

	  break;

      }

      sm+=min(p-a[j],a[j+1]-p);

    }

    cout<<sm<<endl;

  }

  return 0;

}