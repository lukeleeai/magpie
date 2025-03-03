#include<iostream>

#include<cmath>

using namespace std;

int main()

{   int x,i;

    cin>>x;

    for(i=1;pow(2,i)<=x;i++);

    cout<<pow(2,i-1)<<endl;

    return 0;

}