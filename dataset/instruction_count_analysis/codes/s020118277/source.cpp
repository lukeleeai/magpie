#include<cstdio>

using namespace std;



int getdigit(int x){

	int t=x,ret=0;

	while(t){

		ret++;

		t/=10;

	}

	return ret;

}



int cf(int x,int z){

	int ret=1;

	for(register int i=1;i<=z;i++){

		ret*=x;

	}

	return ret;

}



int main(){

	int a,b;

	scanf("%d%d",&a,&b);

	int t1=getdigit(b);

	int t2=cf(10,t1);

	int c=a*t2+b;

	//printf("%d %d %d\n",t1,t2,c);

	for(register int i=1;i<=1000;i++){

		if(i*i==c){

			printf("Yes");

			return 0;

		}

	}

	printf("No");

	return 0;

}