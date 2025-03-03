#include<cstdio>

#include<cstring>

const int N=1100;



int l;

bool f1,f2;

char ch[N];

int main(){

//	freopen("1.in","r",stdin);

//	freopen("1.out","w",stdout);



	ch[0]=3;

	scanf("%s",ch+1);

	l=strlen(ch)-1;

	

	f1=f2=false;

	for(int i=1; i<=l; i++){

		if(ch[i]!='C' and ch[i]!='F') continue;

		

		if(!f1 and ch[i]=='C'){

			f1=true;

			continue;

		}

		if(f1 and ch[i]=='F'){

			f2=true;

			break;

		}

	}

	

	if(f2){

		printf("Yes\n");

	}

	else{

		printf("No\n");

	}

	

	return 0;

}