

// In the name of God

#include "stdc++.h"



using namespace std;

#define Size(x) ((int)(x).size())

#define pb push_back

typedef long long ll;

typedef long double ld;

typedef pair<int,int>pii;

const int INF = 1e9 + 10;

const int MN = 1e5 + 10;



int n , arr[MN];



int main()

{

	ios_base :: sync_with_stdio(false) ,cin.tie(0) , cout.tie(0);

	cin >> n;

	for(int i=0;i<n;++i) cin >> arr[i];

	bool fl = false;

	if(n == 1){

		if(arr[0]&1) cout << "Second\n";

		else cout << "First\n";

		return 0;

	}

	while(1){

		if(*min_element(arr , arr+n) == 1){

			ll sm = 0;

			for(int i=0;i<n;++i) sm += arr[i];

			if((sm-n)%2){

				if(!fl) cout << "First\n";

				else cout << "Second\n";

			}else{

				if(!fl) cout << "Second\n";

				else cout << "First\n";

			}

			return 0;

		}

		int cnt = 0;

		for(int i=0;i<n;++i) if(arr[i]%2 == 0) ++cnt;

		if(cnt&1){

			if(fl) cout << "Second\n";

			else cout << "First\n";

			return 0;

		}else if(n-cnt > 1){

			if(fl) cout << "First\n";

			else cout << "Second\n";

			return 0;

		}

		if(*max_element(arr , arr+n) == 1){

			if(!fl) cout << "Second\n";

			else cout << "First\n";

			return 0;

		}

		for(int i=0;i<n;++i) if(arr[i]&1) arr[i]--;

		int g = -1;

		for(int i=0;i<n;++i){

			if(g == -1) g = arr[i];

			else g = __gcd(g , arr[i]);

		}

		for(int i=0;i<n;++i) arr[i]/=g;

		fl = !fl;

	}

	return 0;

}
