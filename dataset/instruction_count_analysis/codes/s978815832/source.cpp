#include "stdc++.h"

using namespace std;

/*





  1 3 6 10 15

    snow<-|^ + (15 - 10 ) -15



*/

int main()

{



    unsigned long long a, b, x=0;



    cin>>a>>b;

    int i = 1;

    while(i<=(b-a))

    {

        x+=i;

        i++;

    }

    cout<<x-b<<endl;



}
