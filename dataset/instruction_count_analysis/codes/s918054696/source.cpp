#include<cstdio>

using namespace std;

int main(){

	int a=1;

	bool f=true;

	while(a!=3){

		char b=getchar();

		if(f){

			putchar(b);

			f=false;

		}

		if(b==' '){

			b=getchar();

			putchar(b);

			a++;

		}

	}

	return 0;

}