#include"stdc++.h"

using namespace std;

int main()

{

    int n,sum=0;





    cin>>n;

    int m=n;





    while(n!=0)

    {

        sum+=(n%10);

        n=n/10;

    }



    if(m%sum==0)

    {

        cout<<"Yes"<<endl;

    }

    else

        cout<<"No"<<endl;



    return 0;





}
