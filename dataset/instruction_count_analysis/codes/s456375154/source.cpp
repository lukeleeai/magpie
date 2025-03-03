/**OOO**/

#include"stdc++.h"

#define ll long long

#define ull unsigned long long

#define mems(x,y) memset(x,y,sizeof(x))

#define pf printf

#define sc scanf

using namespace std;





int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



    ll n,y,a,b,c;

    cin>>n>>y;



    if(y%10000==0 && y/10000==n)cout<<y/10000<<" "<<0<<" "<<0<<endl;

    else if(y%5000==0 && y/5000==n)cout<<0<<" "<<y/5000<<" "<<0<<endl;

    else if(y%1000==0 && y/1000==n)cout<<0<<" "<<0<<" "<<y/1000<<endl;

    else{



        for(int i=0;i<=n;i++){

            a=10000*i;

            for(int j=0;j<=n-i;j++){

                b=5000*j;

                for(int k=0;k<=n-i-j;k++){

                    c=1000*k;

                    if(a+b+c==y && i+j+k==n){

                        cout<<i<<" "<<j<<" "<<k<<endl;

                        return 0;

                    }

                }

            }

        }

        cout<<-1<<" "<<-1<<" "<<-1<<endl;

    }



return 0;

}
