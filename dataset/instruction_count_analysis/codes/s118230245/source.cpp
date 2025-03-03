#include "stdc++.h"



using namespace std ;



const int MAX = 1e5 + 10 ;



int arr[MAX] ;

int n , m ;

long long pref[2*MAX] , prefcnt[2*MAX] , Ans[2*MAX] ; 



int main()

{

	ios_base::sync_with_stdio(0) ;

	cin.tie(0) ;

	cin>>n>>m ;

	for(int i = 0 ; i < n ; ++i)

	{

		cin>>arr[i] ;

		arr[i]-- ;

	}

	long long ans = 0ll ;

	for(int i = 0 ; i < n-1 ; ++i)

	{

		int dist = (arr[i+1] - arr[i] + m) % m ;

		ans += dist ;

		prefcnt[arr[i]+1]++ ;

		pref[arr[i]+dist+1] -= dist ;

		prefcnt[arr[i]+dist+1]-- ;

	}

	long long sum = 0 , cnt = 0 ;

	for(int i = 0 ; i < m*2 ; ++i)

	{

		cnt += prefcnt[i] ;

		sum += cnt ;

		sum += pref[i] ;

		Ans[i%m] -= max(0ll , sum-cnt) ;

	}

	long long x = *min_element(Ans , Ans + m) ;

	return cout<<ans+x<<"\n" , 0 ;

}		