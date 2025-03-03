#include "stdc++.h"

using namespace std;



int K;



int main() {

    cin>>K;

    long ans=0;

    for (int i=1; i<=K; i++) {

        for (int j=1; j<=K; j++) {

            int codiv;

            codiv=gcd(i,j);

            for (int k=1; k<=K; k++) {

                int codiv2;

                codiv2=gcd(codiv,k);

                ans+=codiv2;

            }

        }

    }

    cout<<ans<<endl;

    return 0;

}
