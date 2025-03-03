#include<cstdio>

#include<string>

#include<string.h>

using namespace std;

char str[100005];

int main(){

	int ans=0;

	scanf("%s",str);

	int N=strlen(str);

	for(int i=0;i<N;i++){

		if(i%2==0){

			if(str[i]=='p'){

				ans--;

			}

		}else{

			if(str[i]=='g'){

				ans++;

			}

		}

	}

	printf("%d\n",ans);

	return 0;

}