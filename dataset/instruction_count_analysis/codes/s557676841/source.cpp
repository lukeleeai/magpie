#include "stdc++.h"

using namespace std;

int main()

{

    int no=1,n,k;

    cin>>n>>k;

    for(int i=0;i<n;i++)

    {

        if(no*2<=no+k)no*= 2;

        else no+=k;

    }

    cout<<no<<endl;

    return 0;

}
