#include<cstdio>

#include<vector>

#include<algorithm>

using namespace std;



const int Maxn=500;



int N,M;

int A[Maxn+5][Maxn+5];



struct Node {

	int a,b,c,d;

	Node(int a1,int b1,int c1,int d1) {

		a=a1,b=b1,c=c1,d=d1;

	}

};

vector<Node> ans;



int main() {

	#ifdef LOACL

	freopen("in.txt","r",stdin);

	freopen("out.txt","w",stdout);

	#endif

	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;i++)

		for(int j=1;j<=M;j++)

			scanf("%d",&A[i][j]);

	for(int i=1;i<=N;i++)

		for(int j=1;j<M;j++)

			if(A[i][j]&1) {

				ans.push_back(Node(i,j,i,j+1));

				A[i][j+1]++;

			}

	for(int i=1;i<N;i++)

		if(A[i][M]&1) {

			ans.push_back(Node(i,M,i+1,M));

			A[i+1][M]++;

		}

	printf("%d\n",ans.size());

	for(int i=0;i<ans.size();i++)

		printf("%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);

	return 0;

}