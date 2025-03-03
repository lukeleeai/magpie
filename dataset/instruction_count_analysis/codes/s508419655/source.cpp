#include"stdc++.h"

using namespace std;

int main()

{

  int A,B,C,D,x,y;

  cin>>A>>B>>C>>D;

  x=A/D;if(A%D>0)x++;y=C/B;if(C%B>0)y++;

  return cout<<((x>=y)?"Yes":"No")<<endl,0;

}