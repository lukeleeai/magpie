#include"stdc++.h"

using namespace std;

int main(){

  string s;cin>>s;

  char a='a';

  for(int i=0;i<26;i++){

    if(!count(s.begin(),s.end(),a)){

      cout<<a;

      return 0;

    }

    a++;

  }

  cout<<"None";

}