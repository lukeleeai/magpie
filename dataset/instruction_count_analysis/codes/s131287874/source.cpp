#include "stdc++.h"

using namespace std;

typedef long long Long;



const Long N = 1e5 + 10;



set<Long> ini[N];

set<Long> fin[N];



Long tree1[N];

Long tree2[N];



Long query1(Long i){

	Long sum=0;

	while(i>0){

		sum+=tree1[i];

		i-=(i&-i);

	}

	return sum;

}

Long query2(Long i){

	Long sum=0;

	while(i>0){

		sum+=tree2[i];

		i-=(i&-i);

	}

	return sum;

}



void update1(Long i, Long val){

	while(i<N){

		tree1[i]+=val;

		i+=(i&-i);

	}

	return;

}

void update2(Long i, Long val){

	while(i<N){

		tree2[i]+=val;

		i+=(i&-i);

	}

	return;

}



Long query(Long x){

	return query1(x)*x-query2(x);

}



void update(Long i, Long j, Long v){

	update1(i,v);

	update1(j+1,-v);

	update2(i,v*(i-1));

	update2(j+1,-j*v);

	return;

}



pair<Long,Long> cambia(Long l, Long r, Long n){

	pair<Long, Long> a,b;

	a = {l,r};

	b = {n-r-1,n-l-1};

	a = min(a,b);

	if(a.second >= n/2){

		Long aux = min(n/2 - 1,n-a.second-2);

		a = {a.first,aux};

	}

	return a;

}



int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	cout.precision(10);

	cout << fixed;

	

	Long m, l, r, n;

	string cad;

	cin >> cad >> m;

	n = cad.size();

	for(Long i = 0; i < m; i++){

		cin >> l >> r;

		l--;

		r--;

		if(l+r == n-1) continue;

		pair<Long,Long> nuevo = cambia(l,r,n);

		ini[nuevo.first].insert(nuevo.second);

	}

	

	for(Long i = 0; i < n/2; i++){

		Long sz = ini[i].size();

		auto it = ini[i].begin();

		if(sz == 1){

			fin[*it].insert(i);

		}else if(sz > 1){

			Long ant = i;

			while(it != ini[i].end()){

				if(ant != i){

					ini[ant].insert(*it);

				}

				fin[*it].insert(ant);

				ant = *it + 1;

				it++;

			}

		}

	}

	

	vector< pair<Long,Long> > rangos;

	

	for(Long i = 0; i < n/2; i++){

		Long sz = fin[i].size();

		auto it = fin[i].begin();

		if(sz == 1){

			rangos.push_back({*it,i});

		}else if(sz > 1){

			Long ant = *it;

			while(it != fin[i].end()){

				it++;

				if(it == fin[i].end()){

					rangos.push_back({ant,i});

				}else{

					rangos.push_back({ant,*it-1});

					ant = *it;

				}

			}

		}

	}

	

	sort(rangos.begin(),rangos.end());

	

	for(Long i = 0; i < rangos.size(); i++){

		l = rangos[i].first + 1;

		r = rangos[i].second + 1;

		Long auxi = (cad[n-l] - 'a') - (query(l) - query(l-1) + (cad[l-1] - 'a'));

		auxi %= 26;

		auxi += 26;

		auxi %= 26;

		update(l,r,auxi);

	}

	

	for(Long i = 0; i < n/2; i++){

		Long aux = query(i+1) - query(i);

		if(((cad[i] - 'a') + aux)%26 != (cad[n-i-1] - 'a')){

			cout << "NO\n";

			return 0;

		}

	}



	cout << "YES\n";

	return 0;

}