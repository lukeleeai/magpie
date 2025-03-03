/*   ꧁༒☬महाकाल☬༒꧂ ꧁༒ঔमहाकालঔ༒꧂

                   

                   ঔৣ۝महाकालᴳᵒᵈ۝ঔৣ            

 

 */ 

#include"stdc++.h"

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;

//template <typename T, typename cmp=less<T>> using oset =tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long 

#define mod 1000000007

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define _it iterator

#define all(_x) _x.begin(),_x.end()

#define f first

#define s second

#define pb push_back

void mahakal(){

	#ifndef ONLINE_JUDGE

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

	freopen("error.txt","w",stderr);

	#endif

}

int main(){

	//mahakal(),fast;

	

	ll n ;

	cin>> n ;

	string str ;

	cin>> str ;

	ll l=0 , r= n-1;

	if(n==1 || n%2==1){

		cout<<"No"<<endl;

		return 0;

	}

	for(ll i=0 , j=ceil(n/2.0) ; j<n ; i++ , j++ ){

		if(str[i]!=str[j]){

			cout<<"No"<<endl;

			return 0;

		}

	}

	cout<<"Yes"<<endl;



	return 0;

}