#include <iostream>

#include <algorithm>

using namespace std;

double arr[1000000];

int main(){

    int a,b,c,i,n;

    cin>>n>>a;

    cout<<a-n+1;

    for(i = 1;i < 2*n-1;i++){

        cout<<' '<<a-n+i+1;

    }

}
