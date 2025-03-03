#include <iostream>

using namespace std;



int main(){

    int n,a[10005]={},cnt=0;

    bool flag=true;

    cin>>n;

    for(int i=0; i<n; i++){

        cin>>a[i];

        while(a[i]%2==0){

            cnt++;

            a[i]/=2;

        }

    }

    cout<<cnt<<endl;

}