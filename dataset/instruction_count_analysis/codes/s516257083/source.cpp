#include <cstdio>

#include <algorithm>

#define maxn 100010

using namespace std;

char in[3];

int n,v[3],p[maxn],q[maxn],ans[maxn];

int main(){

	int i;

	scanf("%d",&n);

	for(i=0;i<3;i++)scanf("%d",&v[i]);//v[0]代表'A'的数量,v[1]代表'B'的数量,v[2]代表'C'的数量

	for(i=1;i<=n;i++)scanf("%s",in),p[i]=in[0]-'A',q[i]=in[1]-'A';

	for(i=1;i<=n;i++){

		if(v[p[i]]>v[q[i]])swap(p[i],q[i]);//让v[]小的在前

		else if(v[p[i]]==v[q[i]]){

			if(i+1<=n&&(q[i]==p[i+1]||q[i]==q[i+1]))swap(p[i],q[i]);//让接下来马上要用到的,在前

		}

		if(!v[q[i]])return 0*printf("No\n");

		v[p[i]]++,v[q[i]]--,ans[i]=p[i];

	}

	printf("Yes\n");

	for(i=1;i<=n;i++)printf("%c\n",'A'+ans[i]);

	return 0;

}