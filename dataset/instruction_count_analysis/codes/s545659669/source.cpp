#include<cstdio>

#include<string>

#include<cstring>



using namespace std;



int h,w;

char tu[105][105];



int main()

{

	scanf("%d %d",&h,&w);

	for(int i = 1;i <= h;i++){

		scanf("%s",&tu[i]);

	}

		/*for(int j = 1;j <= w;j++){

			scanf(" %c",&tu[i][j]);

		}

	}*/

	for(int i = 1;i <= h;i++){

		printf("%s\n%s\n",tu[i],tu[i]);

	}

	return 0;

}