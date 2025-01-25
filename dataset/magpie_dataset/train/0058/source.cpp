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

  int i;

  int a[]={0,1,2,3,5,7,8,9},n;

  while(cin>>n&&n){

    for(i=0;pow(8,i)<=n;i++);

    for(i--;i>=0;i--){

      cout<<a[n/(int)pow(8,i)];

      n%=(int)pow(8,i);

    }

    cout<<endl;

  }

  return 0;

}