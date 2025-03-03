#include<iostream>

using namespace std;

int main()

{

int a1,b1,c1;

cin>>a1>>b1>>c1;

if(a1==b1 && a1!=c1)

{

cout<<"Yes";

}

else if(b1==c1 && c1!=a1)

{

 cout<<"Yes";

}

else if(a1==c1 && a1!=b1)

{

 cout<<"Yes";

}

else

{

 cout<<"No";

}

return 0;

}