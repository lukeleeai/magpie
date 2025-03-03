#include <iostream>

#include <sstream>

#include <fstream>

#include <string>

#include <vector>

#include <deque>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <algorithm>

#include <functional>

#include <utility>

#include <bitset>

#include <cmath>

#include <cstdlib>

#include <ctime>

#include <cstdio>

#include <string.h>

#define rep(i,n) for(int i=0;i<n;i++)

#define forn(i,a,b) for(int i=a;i<=b;i++)

#define INF 2147483647

#define LLINF 9223372036854775807

using namespace std;

map<long long,long long> mp;

int main(){

	long long n,p;

	cin>>n>>p;

	set<long long> s;

	long long P=p;

	vector<long long> v;

	for(long long i=2;i*i<=P;i++){

		if(P%i==0){

			while(p&&p%i==0){

				p/=i;

				s.insert(i);

				mp[i]++;

			}

			v.push_back(P/i);

		}

	}

	for(int i=0;i<v.size();i++){

		while(p&&p%v[i]==0){

			p/=v[i];

			s.insert(v[i]);

			mp[v[i]]++;

		}

	}

	if(s.size()==0){

		s.insert(P);

		mp[P]++;

	}

	long long cnt=1;

	for(set<long long> ::iterator it=s.begin();it!=s.end();it++){

		if(mp[*it]>=n){

			for(int j=0;j<mp[*it]/n;j++)cnt*=*it;

		}

	}

	cout<<cnt<<endl;

	return 0;

}