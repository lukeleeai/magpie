#include <stdio.h>

#include <cmath>

#include <algorithm>

#include <cfloat>

#include <stack>

#include <queue>

#include <vector>

typedef long long int ll;

#define BIG_NUM 2000000000

#define MOD 1000000007

#define EPS 0.000001

using namespace std;



struct Node{

	bool operator<(const struct Node &arg) const{

		return weight < arg.weight;

	};

	int from,to,weight;

};



int parent[101],height[101];



int getParent(int id){

	if(parent[id] == id)return id;

	else{

		return parent[id] = getParent(parent[id]);

	}

}



bool isSame(int a, int b){

	return getParent(a) == getParent(b);

}



void unite(int a,int b){

	int a_parent = getParent(a);

	int b_parent = getParent(b);



	if(a_parent == b_parent)return;



	if(height[a_parent] > height[b_parent]){

		parent[b_parent] = a_parent;

	}else{

		if(height[a_parent] == height[b_parent])height[b_parent]++;

		parent[a_parent] = b_parent;

	}

}





int main(){



	int V,E,ans,maximum,minimum;

	bool FLG;

	Node nodes[4950];



	while(true){

		scanf("%d %d",&V,&E);

		if(V == 0 && E == 0)break;



		for(int i = 1; i <= V; i++){

			parent[i] = i;

			height[i] = 0;

		}



		for(int i = 0; i < E; i++){

			scanf("%d %d %d",&nodes[i].from,&nodes[i].to,&nodes[i].weight);

		}



		sort(nodes,nodes+E);



		maximum = 0;

		minimum = BIG_NUM;



		for(int i = 0; i < E; i++){

			if(!isSame(nodes[i].from,nodes[i].to)){

				maximum = max(maximum,nodes[i].weight);

				minimum = min(minimum,nodes[i].weight);

				unite(nodes[i].from,nodes[i].to);

			}

		}



		FLG = true;

		for(int i = 2; i <= V; i++){

			if(!isSame(1,i)){

				FLG = false;

				break;

			}

		}



		if(!FLG){

			printf("-1\n");

			continue;

		}



		ans = maximum - minimum;



		//start?????°???????????????

		for(int start = 0; start < E;start++){

			for(int end = start; end < E; end++){



				for(int i = 1; i <= V; i++){

					parent[i] = i;

					height[i] = 0;

				}



				maximum = 0;

				minimum = BIG_NUM;



				for(int i = start;i <= end;i++){

					if(!isSame(nodes[i].from,nodes[i].to)){

						maximum = max(maximum,nodes[i].weight);

						minimum = min(minimum,nodes[i].weight);

						unite(nodes[i].from,nodes[i].to);

					}

				}



				FLG = true;

				for(int i = 2; i <= V; i++){

					if(!isSame(1,i)){

						FLG = false;

						break;

					}

				}



				if(FLG){

					ans = min(ans,maximum-minimum);

					break;

				}

			}

		}



		printf("%d\n",ans);

	}



	return 0;

}