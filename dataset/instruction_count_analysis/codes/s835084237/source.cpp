#include <iostream>

#include <algorithm>

#include <cmath>



using namespace std;



const int maxn = 1e5+5 ;

int arr[maxn] ;

int main()

{

    int n ;

    cin >> n ;

    int l = 0 ;

    for (int i = 0 ; i < n ; i++) {

        cin >> arr[i] ;

        if (arr[i]<0)  l++ ;

    }

    sort(arr,arr+n) ;

    int ans = 0 ;

    for(int i = 1 ; i < n-1 ; i++) ans += abs(arr[i]) ;

    ans-=arr[0] ;

    ans+=arr[n-1] ;

    cout << ans << endl ;

    if (l==0) l = 1 ;

    else if (l==n) l=n-1 ;

    for(int i = l ; i < n-1 ; i++) {

        cout << arr[0] << " "<< arr[i] <<endl;

        arr[0] -=arr[i] ;

    }

    for(int i = 0 ; i < l ; i++) {

        cout << arr[n-1] << " " <<arr[i] << endl ;

        arr[n-1] -=arr[i] ;

    }

    return 0;

}
