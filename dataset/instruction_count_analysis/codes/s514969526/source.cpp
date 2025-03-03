

#include"stdc++.h"

using namespace std;

main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    long long i,j,k,l,m,n,o,p,q;

    while(cin>>m>>n>>o>>p)



    {

        if(abs(m-o)<=p)

            cout<<"Yes"<<endl;

        else  if(abs(m-n)<=p&&abs(n-o)<=p)

            cout<<"Yes"<<endl;

        else

            cout<<"No"<<endl;

    }

    return 0;

}
