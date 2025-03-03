#include"stdc++.h"

using namespace std;

int main(){

    int a,b,c,x,ans=0,i,j,k;

    cin>>a>>b>>c>>x;

    for (i=0;i<=a&&500*i<=x;i++){

        for (j=0;j<=b&&100*j+500*i<=x;j++){

            for (k=0;k<=c&&50*k+100*j+500*i<=x;k++){

                if (500*i+100*j+50*k==x){

                    ans++;

                }

            }

        }

    }

    cout<<ans<<endl;

    return 0;

}