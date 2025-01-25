#include <cstdio>

#include <cstdlib>

#include <map>

#include <vector>

#include <string>

#include <sstream>

#include <algorithm>

using namespace std;

map<string,bool> bmap;

int card[10];

int selected[4],temp[4];

bool used[10];

int n,k,num;

void solve(int m) {

	if(m==k) {

		for(int i=0;i<k;i++)temp[i]=selected[i];

		do {

			stringstream str;

			for(int i=0;i<k;i++)str<<selected[i];

			if(bmap.find(str.str())==bmap.end())num++;

			bmap[str.str()]=true;

		}while(next_permutation(selected,selected+k));

		for(int i=0;i<k;i++)selected[i]=temp[i];

	}else {

		for(int i=0;i<n;i++) {

			if(used[i]==false) {

				used[i]=true;

				selected[m]=card[i];

				solve(m+1); 

				used[i]=false;

			}

		}

	}

}

int main() {

	while(scanf("%d %d",&n,&k),n) {

		for(int i=0;i<n;i++)scanf("%d",&card[i]);

		fill(used,used+10,0);

		bmap.clear();

		num=0;

		solve(0);

		printf("%d\n",num);

	}

}