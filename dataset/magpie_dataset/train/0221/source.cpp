#include <iostream>

using namespace std;

int main(){

  int k,s,c,i;

  while(1){

    cin >>k;

    if (!k) break;

    for(i=0,s=0;i<k*(k-1)/2;i++)

      cin>>c,s+=c;

    cout <<s/(k-1)<<endl;   

  }

  return 0;

}