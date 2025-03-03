#include"stdc++.h"

using namespace std;

long long gcd(long long a, long long b);

int main(){

    long long a,b;

    cin>>a>>b;

    long long n=gcd(a,b);

    //cout<<n<<endl;

    vector<int> prime(1000001,0);

    int ans=1;

    for(long long i=2;i*i<=n;i++){

        //cout<<i<<" "<<n<<endl;

        if(n%i==0){

            while(n%i==0){

                n/=i;

            }

            ans++;

        }

    }

    if(n!=1)ans++;

    cout<<ans<<endl;

    return 0;

}



long long gcd(long long a,long long b){

    if(b==0)return a;

    else return gcd(b,a%b);

}