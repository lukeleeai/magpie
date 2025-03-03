#include"stdc++.h"

using namespace std;



#define pb push_back

#define MAX 100005

#define ff first

#define ss second

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }



void err(istream_iterator<string> it) {}

template<typename T, typename... Args>

void err(istream_iterator<string> it, T a, Args... args) {

	cerr << *it << " = " << a << endl;

	err(++it, args...);

}



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll, ll> pll;



int m;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cin>>m;

    cout<<(m>=30?"Yes\n":"No\n");

}