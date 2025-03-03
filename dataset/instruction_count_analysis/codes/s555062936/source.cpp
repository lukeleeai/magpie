#include"stdc++.h"

using namespace std;

int main(){

    int n,q,a[1000009],x;

    cin >> n;

    for(int i=1; i<=n; i++){

        cin >> a[i];

    }

    sort(a+1,a+n+1);

    long long jum=0;

    for(int i=1; i<=n; i++){

    	for(int j=i+1; j<=n; j++){

    		jum+=lower_bound(a+j+1,a+n+1,a[i]+a[j])-a-j-1;

    	}

    }

    cout << jum << endl;

}