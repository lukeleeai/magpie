#include<cstdio>

#include<cstring>



using namespace std;



int main(){

	char s[205];

	char s1[205];

	int a[205];

	int b[205];

	int flag = 0;

	scanf("%s%s",s,s1);

	int len = strlen(s);

	int len1 = strlen(s1);

	if(len > len1) printf("GREATER\n");

	else if(len < len1) printf("LESS\n");

	else if(len == len1){

		for(int i = 0; i < len; i++){

			a[i] = s[i] - '0';

			}

		for(int i = 0; i< len1; i++){

			b[i] = s1[i] - '0';

			}

		for(int i =0; i < len; i++){

			if(a[i] > b[i]){

				flag = 1;

				printf("GREATER\n");

				break;

			}			

			else if(a[i] < b[i]){

				flag = 1;

				printf("LESS\n");

				break;

				}

		}

		if(flag == 0) printf("EQUAL\n");

	}

}