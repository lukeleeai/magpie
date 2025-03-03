#include"stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;



typedef long long ll;

typedef pair<int,int> ii;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;



ll eval(string &s) {

	ll a=0, ret=0;

	for (char ch : s)

		if(ch=='A') a++;

		else ret+=a;

	return ret;

}



int main() {

	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	string s; cin>>s;

	deque<char> dq;

	for (char ch : s) {

		if(dq.empty()) dq.push_back(ch);

		else {

			if(ch=='C'&&dq.back()=='B') dq.pop_back(), dq.push_back('D');

			else dq.push_back(ch);

		}

	}



	string t;

	while(!dq.empty())

		t+=dq.front(), dq.pop_front();

	ll ret=0;

	for (int i=0; i<t.size(); i++)

		if(t[i]=='B'||t[i]=='C')

			t[i]=' ';

	stringstream ss(t);

	string cur;

	while(ss>>cur)

		ret+=eval(cur);

	cout<<ret<<"\n";

	return 0;

}