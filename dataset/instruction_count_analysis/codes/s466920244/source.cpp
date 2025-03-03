#include <iostream>

#include <cmath>



using namespace std;



int i,k,t,x,xmax;

int main()

{

    cin>>k>>t;

    for(i=1;i<=t;i++){

        cin>>x;

        xmax=max(xmax,x);

    }

    cout<<max(2*xmax-k-1,0)<<'\n';

    return 0;

}
