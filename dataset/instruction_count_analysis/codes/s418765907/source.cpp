#include "stdc++.h"

using namespace std;



int main() {



    ios_base::sync_with_stdio(false);

    cin.tie(0);



    long long n, k;

    cin >> n >> k;

    vector <long long> arr(n);

    for(int i=0;i<n;i++)

        cin >> arr[i];



    long long cost = LONG_LONG_MAX;

    for(int i=0;i<=n-k;i++){

        if(arr[i] < 0 && arr[i+k-1] <= 0){

            cost = min(cost, abs(arr[i]));

        }

        else if( arr[i]>=0 && arr[i+k-1] > 0){

            cost = min(cost, arr[i+k-1]);

        }

        else{

            cost= min(cost, min(abs(arr[i])*2+arr[i+k-1], abs(arr[i])+arr[i+k-1]*2));

        }

    }

    cout << cost << '\n';

    return 0;

}
