#include <iostream>

using namespace std;

int main() {

    int a,b;

    cin>>a>>b;

    int x=a+b;

    int y=a-b;

    int z=a*b;

    if(x>=y&&x>=z)cout<<x;

    else if(x<=y&&y>=z) cout<<y;

    else if(z>=x&&z>=y) cout<<z;



    }
