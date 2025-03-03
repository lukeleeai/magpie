#include<cstdio>

#include<string.h>

using namespace std;

char s[1000000];

int len;

bool b=true;

int main(){

	scanf("%s",&s);

	len=strlen(s);

	for (int i=0;i<len;i++){

		if ((s[i]=='d')&&(s[i+1]=='r')&&(s[i+2]=='e')&&(s[i+3]=='a')&&(s[i+4]=='m')&&(s[i+5]=='e')&&(s[i+6]=='r')){

			i+=6;

			if ((s[i-1]=='e')&&(s[i]=='r')&&(s[i+1]=='a')&&(s[i+2]=='s')&&(s[i+3]=='e')&&(s[i+4]=='r')){

				i+=4;

			}else if ((s[i-1]=='e')&&(s[i]=='r')&&(s[i+1]=='a')&&(s[i+2]=='s')&&(s[i+3]=='e')){

				i+=3;

			}

		}else if ((s[i]=='d')&&(s[i+1]=='r')&&(s[i+2]=='e')&&(s[i+3]=='a')&&(s[i+4]=='m')){

			i+=4;

		}else if ((s[i]=='e')&&(s[i+1]=='r')&&(s[i+2]=='a')&&(s[i+3]=='s')&&(s[i+4]=='e')&&(s[i+5]=='r')){

			i+=5;

		}else if ((s[i]=='e')&&(s[i+1]=='r')&&(s[i+2]=='a')&&(s[i+3]=='s')&&(s[i+4]=='e')){

			i+=4;

		}else {

			b=false;

		}

		if (b==false){

			break;

		}

	}

if (b==true){

	printf("YES");

}else{

	printf("NO");

}

return 0;}