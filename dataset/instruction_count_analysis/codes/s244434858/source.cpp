#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i=0;i<n;++i)

#define REP(i, k, n) for(int i=k; i<=n; ++i)

#define REPR(i, k, n) for(int i=k; i>=n; --i)

#define MAX 2001

#define F first

#define S second

#define PB push_back

#define MP make_pair

#define r return

typedef long long ll;

typedef long long int lli;

typedef unsigned long long ull;

typedef unsigned int long long uill;

int main(){



	ios::sync_with_stdio(0);

	cin.tie(0);

	set<char> s1;

	vector<int> v;

	int cnt=0;

	int flag=1;

    int a,b,c,d;



    cin>>a>>b>>c>>d;



     int ma = max(a,c);

     int mi = min(b,d);



    

    cout << max(0, mi-ma) << "\n";



   //50 55 25 40







  // ----------50------55----

  // ---25-40------



    return 0;





}