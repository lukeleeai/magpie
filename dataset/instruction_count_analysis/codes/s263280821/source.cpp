#include"stdc++.h"

using namespace std;

vector<int>v;

int main()

{

  int n,k;

  cin>>n;

  string s;

  cin>>s;

  for(int i=0;i<s.size();i++)

  {

     v.push_back(s[i]);

  }

  for(int i=0;i<s.size();i++)

  {

      k=v[i]+n;

    if(k<=90)

        cout<<char(k);

    else

    {

        cout<<char(k-26);

    }

  }

  cout<<endl;



}
