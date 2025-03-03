#include<cstdio>

using namespace std;

int n,t[110],m,Pi,Xi,Time;

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%d",&t[i]);

		Time=Time+t[i];

	}

	scanf("%d",&m);

	for(int i=1;i<=m;i++){

		scanf("%d%d",&Pi,&Xi);

		printf("%d\n",Time-t[Pi]+Xi);

	}

	//AC!

	return 0;

}