#include <iostream>

using namespace std;

long long n,m;



int main(void){

    cin>>n>>m;

    if(2*n>=m)cout<<m/2<<endl;

    else cout<<n+(m-2*n)/4<<endl;

    return 0;

}
