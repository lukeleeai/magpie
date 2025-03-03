#include"stdc++.h"

using namespace std;

int main()

{

    int n,k,x,y,c=1,i,sum=0;

    cin>>n>>k>>x>>y;

    for(i=0;i<n;i++)

    {

        if(c<=k){

           sum+=x;

           c++;

        }

        else

            sum+=y;

    }

    cout<<sum<<endl;





}
