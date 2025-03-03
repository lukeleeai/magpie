#include<cstdio>

#include<cstring>

#include<string>



using namespace std;



char w[27];

int flag[27];

int vis;



int main()

{

	scanf("%s",w);

	int len = strlen(w);

	for(int i = 0;i < len;i++){

		flag[w[i]-'a' + 1] ++;

	}

	for(int i = 1;i <= 26;i++){

		if(flag[i] != 1 && flag[i] != 0) vis = 1;

	}

	if(vis == 1) printf("no\n");

	else printf("yes\n");

	return 0;

}