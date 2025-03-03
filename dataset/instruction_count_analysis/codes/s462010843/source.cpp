#include<cstdio>

#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

int n;

struct node{

	string nm; int sc,id;

	bool operator <(const node &j) const {

		return nm<j.nm||(nm==j.nm&&sc>j.sc);

	}

}re[200010];

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;++i){

		cin>>re[i].nm>>re[i].sc;

		re[i].id=i;

	}

	sort(re+1,re+n+1);

	for(int i=1;i<=n;++i){

		cout<<re[i].id<<endl;

	}

	return 0;

}