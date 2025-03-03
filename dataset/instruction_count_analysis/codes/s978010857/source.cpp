#include "stdc++.h"

 

#define pb push_back

#define ff first

#define ss second

#define all(x) (x).begin(), (x).end()

#define ll long long

#define ii pair<int,int>

#define vi vector<int>

#define vll vector<ll>

#define vii vector<ii>

#define debug cout << "Ok" << endl;



using namespace std;



void solve(){



	return;

}

 

int32_t main(){

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	int n,m,aux,me=10000000,cont=0;

	cin >> n >> m;



	while(n--){

		cin >> aux;

		m-=aux;

		me = min(me, aux);

		cont++;

	}

	cout << cont + m/me << endl;

	return 0;

}