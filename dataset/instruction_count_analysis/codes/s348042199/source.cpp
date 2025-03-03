#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;



int main(int argc, const char * argv[]) {

    int n,k;

    cin >> n >> k ;

    int arr[1000];

    for(int i=0;i<n;i++){

        cin >> arr[i] ;

    }

    for(int i=0;i<n;i++){

        for(int j=0;j<n-1;j++){

            if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);

        }

    }

    int sum=0;

    for(int i=0;i<k;i++){

        sum+=arr[i];

    }

    cout << sum << endl ;

}
