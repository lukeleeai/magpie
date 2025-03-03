#include"stdc++.h"

using namespace std;

int main()

{

    int x,y,a,b;

    cin>>x>>y>>a>>b;

    int r=x-a;

    int m=(x*y)-(a*y)-(b*(x-a));

    cout<<m<<endl;

}


