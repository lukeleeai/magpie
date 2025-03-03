#include<cstdio>

#include<cstring>

#include<algorithm>

#include<string>

using namespace std;

int a[10010],ans[103][103];



int main()

{

	int h,w;

	scanf("%d%d",&h,&w);

	int N;

	scanf("%d",&N);

	

	for(int i=1;i<=N;i++){

		scanf("%d",&a[i]);

	}

	int n = 1,m = 1,inc=1;

	for(int i=1;i<=N;i++){

		int cnt=a[i];

		for(;cnt!=0;cnt--){

			ans[n][m] = i;

			m+=inc;

			if(m==w+1||m==0){

				n++;

				inc = -inc;

				m+=inc;

			}

		}

	}	

	

	for(int i=1;i<=h;i++){

		for(int j=1;j<=w;j++){

			printf("%d%c",ans[i][j],j==w?'\n':' '); 

		} 

	} 

	return 0;

} 