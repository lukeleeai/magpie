//xahid f

#include"stdc++.h"

using namespace std;

int main()

{

    int val[3],k;

    cin>>val[0]>>val[1]>>val[2]>>k;

    sort(val,val+3);

    cout<<val[0]+val[1]+val[2]*pow(2,k)<<endl;

    

}