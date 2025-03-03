#include <cstdio>

#include <cstring>

#include <cmath>

#include <string>

#include <iostream>

#include <iomanip>

#include <sstream>

#include <set>

#include <map>

#include <queue>

#include <vector>

#include "stdc++.h"

#define INF 0x3f3f3f3f

#define eps 1e-8

#define mp make_pair

#define np next_permutation

#define pb push_back

#define all(x) (x.begin(),x.end())

#define rep(i,a,n) for(int i=a;i<n;++i)

#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define ms(x,a) memset((x),a,sizeof(x))

#define fi first

#define se second 

using namespace std;

const int maxn=1e5+5;

const int maxl=26;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef pair<int,int> pii;

 

 

int a,b;

int main(){

	while(cin>>a>>b)

	cout<<a*b-a-b+1<<endl;

} 