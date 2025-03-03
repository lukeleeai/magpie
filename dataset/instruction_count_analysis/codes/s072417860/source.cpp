#include<iostream>

#include<iomanip>

using namespace std;

int main(){

    double n,result;

    cin>>n;

    n=n/3;

    result=n*n*n;

    printf("%.12f\n",(double)result);

}