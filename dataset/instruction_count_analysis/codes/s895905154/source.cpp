#include <algorithm>

#include <bitset>

#include <complex>

#include <deque>

#include <exception>

#include <fstream>

#include <functional>

#include <iomanip>

#include <ios>

#include <iosfwd>

#include <iostream>

#include <istream>

#include <iterator>

#include <limits>

#include <list>

#include <locale>

#include <map>

#include <memory>

#include <new>

#include <numeric>

#include <ostream>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <stdexcept>

#include <streambuf>

#include <string>

#include <typeinfo>

#include <utility>

#include <valarray>

#include <vector>

#if __cplusplus >= 201103L

#include <array>

#include <atomic>

#include <chrono>

#include <condition_variable>

#include <forward_list>

#include <future>

#include <initializer_list>

#include <mutex>

#include <random>

#include <ratio>

#include <regex>

#include <scoped_allocator>

#include <system_error>

#include <thread>

#include <tuple>

#include <typeindex>

#include <type_traits>

#include <unordered_map>

#include <unordered_set>

#endif



long long max(long long x, long long y){return (x > y ? x : y);}

long long min(long long x, long long y){return (x < y ? x : y);}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }



#define ll int

#define FOR(i,a) for(ll i=0;i<(ll)a.size();i++)

#define pb push_back

#define ld long double

#define mp make_pair

#define F first

#define S second

#define pii pair<ll,ll> 



using namespace :: std;



const ll maxn=6e5+500;

const ll inf=1e9+800;

const ll mod=1e9+7;



vector<char> de;

deque<ll>  fargh;



void makee(){

	fargh.clear();

	for(ll i=1;i<de.size();i++){

		if(de[i]!=de[i-1]){

			fargh.pb(de[i-1]);

		}

	}

}

void pel(){

	ll tol=0;

	for(ll i=0;i<de.size();i++){

		tol=i;

		if(i+1!=de.size() && de[i]!=de[i+1]){

			fargh.pop_front();

		}

		if(de[i]=='9'){

			de[i]='0';

		}else{

			de[i]++;

			break;

		}

	}	

	for(ll i=tol;i>=0;i--){

		if(i+1!=de.size()){

			if(de[i]!=de[i+1]){

				fargh.push_front(de[i]);

			}

		}

	}

}

bool good(){

	if(de.size()==0)return 0;

	if(fargh.size()==0)return 1;

	if(fargh.back()<de.back())return 0;

	else  return 1;

}

void pri(){

	for(ll i=(ll)de.size()-1;i>=0;i--){

		cout<<de[i];

	}

	cout<<"***"<<endl;

}

int main(){

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	



	string s;

	cin>>s;

	reverse(s.begin(),s.end());

	for(ll i=0;i<s.size();i++){

		de.pb(s[i]);

	}

	makee();

	ll ans=0;

	while(de.size()){

	//	pri();

		ans++;

		while(good()){

			char c=de.back();

			de.pop_back();

			if(de.size()!=0){

				if(de.back()!=c){

					fargh.pop_back();

				}

			}

		}

		if(de.size()){

			char c=de.back();

			de.pop_back();

			if(de.size()){

				if(de.back()!=c){

					fargh.pop_back();

				}

			}

			pel();

		}

	}

	cout<<ans;

}


