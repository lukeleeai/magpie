#include "stdc++.h"

using namespace std;

int main(){

  int a,b,c;

  string mon="RYGB";

  cin>>a>>b>>c;

  for(int i=0;i<a;++i){

    for(int j=0;j<b;++j){

      int m=((i+j)%(c*2)+(c*2))%(c*2)/c,n=((i-j)%(c*2)+(c*2))%(c*2)/c;

      cout<<mon[m*2+n];

    }

    cout<<endl;

  }

}
