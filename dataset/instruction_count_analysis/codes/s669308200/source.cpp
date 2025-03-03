#include "stdc++.h"

using namespace std;



int K;



int main() {

    cin>>K;

    long ans=0;

    for (int i=1; i<=K; i++) {

        for (int j=1; j<=K; j++) {

            int codiv;

            for (int k=1; k<=min(i,j); k++) {

                if (i%k==0 && j%k==0) codiv=k;

            }

            for (int k=1; k<=K; k++) {

                int codiv2;

                for (int l=1; l<=min(i,j); l++) {

                    if (k%l==0 && codiv%l==0) codiv2=l;

                }

                ans+=codiv2;

            }

        }

    }

    cout<<ans<<endl;

    return 0;

}
