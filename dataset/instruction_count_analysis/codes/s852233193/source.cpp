#include<iostream>

using namespace std;

int main(){

    int A[100010],n,i,ans=1;

    cin>>n;

    for(i=1;i<=n;i++) cin>>A[i];

    long long min=2,max=2;

    for(i=n;i>=1;i--){

        max=A[i]*(max/A[i]);

        max=max+A[i]-1;

        min=A[i]*((min-1)/A[i]+1);

        if(max<min){

            ans=0;

            break;

        }

    }

    if(ans==0) cout<<-1<<endl;

    else cout<<min<<" "<<max<<endl;

    return 0;

}


