/*Bismillahir Rahmanir Rahim*/

#include"stdc++.h"

using namespace std;

int main()

{

    long long int n,i,j,min,a[10];

    cin>>n;

    min=1000000000000009;

    for(i=0; i<5; i++)

    {

        cin>>a[i];

        if(a[i]<min)

            min=a[i];

    }

    if(n%min==0)

        cout<<(n/min)+4<<endl;

    else

       cout<<(n/min)+5<<endl;

    return 0;

}
