#include "stdc++.h"

using namespace std;

int main(){

    char a[1000000],b[1000000];

    int n;

    cin>>a>>b;

    n=strcmp(a,b);

    if(n==0)cout<<"H";

    else cout<<"D";

    return 0;

}