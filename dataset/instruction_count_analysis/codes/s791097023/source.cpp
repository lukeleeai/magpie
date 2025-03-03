#include <algorithm>

#include <stdio.h>

using namespace std;

struct Apple{

	long value;

	int type;

};

Apple apple[300100];



bool judge(Apple a,Apple b){

	return a.value>b.value;

}



int main()

{

	int X,Y,A,B,C;

	scanf("%d%d%d%d%d",&X,&Y,&A,&B,&C);

	for(int i=0;i<A;i++){

		scanf("%ld",&apple[i].value);

		apple[i].type=1;

	}

	for(int i=A;i<A+B;i++){

		scanf("%ld",&apple[i].value);

		apple[i].type=2;

	}

	for(int i=A+B;i<A+B+C;i++){

		scanf("%ld",&apple[i].value);

		apple[i].type=0;

	}

	sort(apple,apple+A+B+C,judge);





	long long sum=0;

	int count_X=X,count_Y=Y,num=X+Y;

	for(int i=0;i<A+B+C;i++,num--){

		if(num==0) break;

		if(apple[i].type==0)

			sum+=apple[i].value;

		else if(apple[i].type==1&&count_X){

			sum+=apple[i].value;

			count_X--;

		}

		else if(apple[i].type==2&&count_Y){

			sum+=apple[i].value;

			count_Y--;

		}

		else num++;

	}

	printf("%ld",sum);

	return 0;

}
