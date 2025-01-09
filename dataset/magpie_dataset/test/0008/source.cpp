#include "stdc++.h"

using namespace std;



long long n,a,m,b,qq,k;

string ss;

int main() {

    cin>>n>>k;

    long long l[n],l1[n];

    for (int i=0; i<=n; i++){

        l[i]=0;

        l1[i]=0;

    }

    for (int i=0; i<n; i++){

        cin>>l[i];

    }

    for (int i=1; i<n; i++){

        l1[i]=l1[i-1]+abs(l[i-1]-l[i]);

        for (int j=1; j<=min(i*1ll,k); j++){

            l1[i]=min(l1[i], l1[i-j]+abs(l[i-j]-l[i]));

        }

    }

    cout<<max(0*1ll,l1[n-1])<<endl;

}
