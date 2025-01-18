#include<iostream>

#include<cstring>

using namespace std;

char a[101];

int main(){

    cin>>a;

    cout<<a[0]<<strlen(a)-2<<a[strlen(a)-1];

    return 0;

}