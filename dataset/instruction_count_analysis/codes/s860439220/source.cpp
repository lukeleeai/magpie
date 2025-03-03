#include <cstdio>

#include <algorithm>

#include <utility>

#include <vector>

#include <queue>

#include <functional>

#include <stack>

#include <set>

#include <map>

#include <ctype.h>

#include <cstring>

#include <string>

#include <iostream>



#define fi first

#define se second

#define sz(x) ((int)x.size())



using namespace std;



typedef long long lli;

typedef pair<int,int> pii;

typedef pair<lli,int> pli;

typedef pair<lli,lli> pll;



int n,m;

char str[5010],tmp[5010];



void make(int l) {

	vector<char> arr;

	for(int i=0;i<n-l && m>0;i++) {

		int f=1;

		for(int j=0;j<l;j++) if(str[i+j]!=tmp[j]) {

			f=0;

			break;

		}

		if(f) arr.push_back(str[i+l]);

	}

	if(arr.empty() || !m) return;

	

	sort(arr.begin(),arr.end());

	for(int i=0;i<sz(arr) && m>0;i++) {

		if(i!=0 && arr[i]==arr[i-1]) continue;

		tmp[l] = arr[i];

		m--;

		if(!m) printf("%s\n",tmp);

		else make(l+1);

		tmp[l] = 0;

	}

}



int main() {

	scanf("%s",str);

	scanf("%d",&m);

	n=strlen(str);



	make(0);

	

	return 0;

}
