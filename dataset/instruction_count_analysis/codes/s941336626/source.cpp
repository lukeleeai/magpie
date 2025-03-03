#include "stdc++.h"

#define endl "\n"



using namespace std;



int main(){

    int a, temp, len, sum=0;

    cin >> a;

    len=log10(a)+1;

    temp=a;

    for(int i=0; i<len; i++){

        sum+=temp%10;

        temp/=10;

    }

    cout << (a%sum==0? "Yes":"No") << endl;

    return 0;

}
