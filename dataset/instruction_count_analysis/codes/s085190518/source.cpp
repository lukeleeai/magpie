#include <iostream>

#include <cstdio>

using namespace std;

int main() {

    int N=0,A=0,B=0;

    cin>> N>>A>>B;

    int tmp = N*A;

    if(B<tmp){

        cout<<B<<endl;

    }else{

        cout<<tmp<<endl;

    }

    return 0;

}