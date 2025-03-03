#include "stdc++.h"

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);

#define pb push_back

#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

const int maxn = 1e6+10;

const int maxM = 1e6+10;

const int inf = 0x3f3f3f3f;



int K,A,B;

int main(){

	// debug;

	ios;



	cin>>K>>A>>B;

	if(B/K - (A-1)/K > 0) cout<<"OK\n";

	else cout<<"NG\n";



	return 0;

}
