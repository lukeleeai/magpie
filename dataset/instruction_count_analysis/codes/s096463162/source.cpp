#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <cstdlib>

#include <algorithm>

using namespace std;



#define MAX_N 100005

#define mm(a,b) memset(a,b,sizeof(a))

#define ll long long



ll n,k,ans;



int main() {

    while(~scanf("%lld %lld",&n,&k)){

        if(n == 1){

            ans = k;

        }

        else if(n == 2){

            ans = k * (k - 1);

        }

        else{

            if(n % 2 == 1 && k == 2){

                ans = 0;

            }

            else{

                ans = k * pow((k-1),(n-1));

            }

        }

        cout<<ans<<endl;

    }

    return 0;

}