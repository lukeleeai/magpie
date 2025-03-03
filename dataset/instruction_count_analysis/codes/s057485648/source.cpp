#include<iostream>

using namespace std;

int main(){

    int a,b,c,d;

    cin>>a>>b>>c;

    d=max(a,b);

    cout<<(c+d-1)/d;

    return 0;

}