#include"stdc++.h"

#define range(i,a,b) for(int i = (a); i < (b); i++)

#define rep(i,b) for(int i = 0; i < (b); i++)

#define all(a) (a).begin(), (a).end()

#define show(x)  cerr << #x << " = " << (x) << endl;

#define int long long

using namespace std;



template <typename X, typename T>

auto vectors(X x, T a) {

	return vector<T>(x, a);

}



template <typename X, typename Y, typename Z, typename... Zs>

auto vectors(X x, Y y, Z z, Zs... zs) {

	auto cont = vectors(y, z, zs...);

	return vector<decltype(cont)>(x, cont);

}



template<typename T>

ostream& operator << (ostream& os, vector<T>& v){

	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;

}

template<typename T>

istream& operator >> (istream& is, vector<T>& v){

	for(T& x: v){ is >> x; } return is;

}



const int M = 1000000007;



signed main(){

	int n;

	string s;

	cin >> n >> s;



	vector<int> num(26, 0);

	for(auto i : s){

		num[i - 'a']++;

	}





	int ans = 1;

	rep(i,num.size()){

		(ans *= num[i] + 1) %= M;

	}



	cout << ans - 1 << endl;

}
