#include <iostream>

#include <cstdlib>

#include <algorithm>

#include <cstring>

using namespace std;



int main()

{

  string s;

  int ok=0,ok1=1,cnt=0;

  cin>>s;

  int len=s.length();

  for(int i=0;i<len;++i)

  {

  	if(s[i]=='C'&&ok1) { ok=1; ok1=0; }

  	if(s[i]=='F'&&ok) { cout<<"Yes"<<endl; system("pause"); return 0; }

  }

  cout<<"No"<<endl;

  system("pause"); 

  return 0;

}
