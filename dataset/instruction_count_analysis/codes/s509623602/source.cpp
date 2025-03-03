#include<iostream>

const int N=100001;

using namespace std;

int main(){

    int n,x[N],y[N],t[N];

    cin>>n;

    for(int i=1;i<=n;i++)

        cin>>t[i]>>x[i]>>y[i];

    for(int i=1;i<=n;i++)

        if(x[i]+y[i]>t[i]||(t[i]-x[i]-y[i])%2!=0)

        {

            cout<<"No";

            return 0;   

        }

    cout<<"Yes";

    return 0;

}