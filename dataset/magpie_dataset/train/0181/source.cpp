//ツ暗。ツつ、ツづァツつオツつ「

#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#include <utility>

using namespace std;

struct road{

	int a,b,l;

	road(int a_,int b_,int l_):a(a_),b(b_),l(l_){}

};

typedef pair<int,int> pii;

int main(){

	int n,m,k,a,b,l,s;

	vector<road> rd;

	vector<pii> town[3001];

	int len[3001];

	priority_queue<pii,vector<pii>,greater<pii> > qu;

	int inf = 1e9;



	for(cin>>n>>m>>k;m--;rd.push_back(road(a,b,l))){

		cin>>a>>b>>l;

		town[a].push_back(make_pair(b,l));

		town[b].push_back(make_pair(a,l));

	}

	for(;k--;qu.push(make_pair(0,s)))

		cin>>s;



	for(fill(len,len+n+1,-1);!qu.empty();){

		pii pi = qu.top();

		qu.pop();

		if( len[pi.second] == -1 ){

			len[pi.second] = pi.first;

			for(

				vector<pii>::iterator it=town[pi.second].begin();

				it != town[pi.second].end();

				++it

			){

				qu.push(make_pair(pi.first+it->second,it->first));

			}

		}

	}

	

	s=0;

	for(vector<road>::iterator it = rd.begin(); it != rd.end();	++it ){

		s = max(max( s, len[a] ),

				max( len[b], (len[it->b] + it->l - len[it->a] + 1)/2 + len[it->a] )

		);

	}

	cout << s << endl;

}