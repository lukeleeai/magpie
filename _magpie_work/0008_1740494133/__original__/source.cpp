#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;



int main(){

  vector<int> v,s(10001);

  int a,b,n,o=0;

  while(cin>>b){

    fill(s.begin(),s.end(),0);

    o =0;

    if(b==0) break;

    else{

    for(int i=0;i<b;i++){

      cin>>a;

      v.push_back(a);

    }

    for(int i = 0; i < b; i++){

      int sum = 0;

      for(int j = i; j < b; j++){

	sum += v[j];

	s.push_back(sum);

      }

    } 





  int d = *max_element(s.begin(),s.end());

  cout<<d<<endl;

    }

    s.clear(),v.clear();

  }

}