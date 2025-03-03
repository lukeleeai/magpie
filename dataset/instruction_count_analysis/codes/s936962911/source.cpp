#include"stdc++.h"

using namespace std;



#define lb(x) x & -x

const int _ = 3e5 + 7; int N , arr[_];

void add(int x){while(x <= N){++arr[x]; x += lb(x);}}

int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lb(x);} return sum;}



#define ll long long

ll c(vector < int > p){

	ll sum = 0; memset(arr , 0 , sizeof(arr)); while(!p.empty()){sum += qry(p.back()); add(p.back()); p.pop_back();} return sum;

}



int main(){

	bool flg = 1; vector < int > p1 , p2 , p3; cin >> N;

	for(int x , i = 1 ; i <= N ; ++i){cin >> x; p1.push_back(x); (i & 1 ? p2 : p3).push_back(x); flg &= !((i ^ x) & 1);}

	puts(flg & (c(p1) == 3 * (c(p2) + c(p3))) ? "Yes" : "No"); return 0;

}
