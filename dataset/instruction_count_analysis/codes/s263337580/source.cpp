#include <iostream>

#include <cstring>

using namespace std;

int pd[100010],arr[100010];

int main()

{

    int n,m,ans=0,T=0;

    memset(pd,0,sizeof(pd));

    cin>>n;

    

    for(int i=1;i<=n;i++)

    {

        cin>>arr[i];

    }



    T=arr[2]-arr[1];

    for (int i=3; i<=n; i++) {

        if(T==0)T=arr[i]-arr[i-1];

        if(1LL* T * (arr[i]-arr[i-1])<0){

            ans++;

            T=0;

        }

    }

    

    cout<<ans+1<<endl;

}