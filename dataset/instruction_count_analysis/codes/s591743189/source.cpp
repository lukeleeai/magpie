#include"stdc++.h"



using namespace std;



#define int long long



int n,x,dem;



main()

{

    cin>>n;

    for(int i=1;i<=n;i++)

    {

        cin>>x;

        if(x%2==1) dem=1;

    }

    if(dem==0) cout<<"second";

    else cout<<"first";

}
