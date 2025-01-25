#include <cstdio>

#include <iostream>

#include <map>

#include <vector>

#include <tuple>

#include <algorithm>

using namespace std;



int a[200010];

int prv[200010],nxt[200010];

bool win[200010];



int main(void){

	int n,m,q;

	cin >> n >> m >> q;



	for(int i=0;i<n;++i){

		prv[i]=(i+n-1)%n,nxt[i]=(i+1)%n;win[i]=true;

	}

	int cur=0;

	for(int i=0;i<m;++i){

		cin >> a[i];

		if(a[i]&1){

			for(int j=0;j<a[i];++j) cur=prv[cur];

		}else{

			for(int j=0;j<a[i];++j) cur=nxt[cur];

		}

		win[cur]=false;

		nxt[prv[cur]]=nxt[cur];

		prv[nxt[cur]]=prv[cur];

		cur=nxt[cur];

	}



	for(int i=0;i<q;++i){

		int in;

		cin >> in;

		cout << win[in] << endl;

	}

	return 0;

}