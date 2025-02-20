#include<vector>

#include<list>

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

  int s[100],b,m,n;

  while(cin>>n>>m&&n+m){

    for(i=0;i<m;i++)

      cin>>s[i];

    for(i=0;i<n;i++){

      for(j=0;j<m;j++){

	cin>>b;

	s[j]-=b;

      }

    }

    for(i=0;i<m;i++){

      if(s[i]<0)

	break;

    }

    if(i==m)

      cout<<"Yes"<<endl;

    else

      cout<<"No"<<endl;

  }

  return 0;

}