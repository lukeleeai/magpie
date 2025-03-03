#include<stdio.h>

#include<algorithm>

using namespace std;



int a,b,c,x,y;



int main(){

//	freopen("inb.txt","r",stdin);

	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

	int com = min(x,y);//a b棋盘公共的部分 com套a+b 

	int sum = 0; 

	if(a+b>=c*2){//套装更优惠 

		sum += com*c*2; 

		if(x>=y){

			if(a>=c*2){

				sum += (x-y)*2*c;

			}else{

				sum += (x-y)*a;

			}	

		}else{

			if(b>=c*2){

				sum += (y-x)*2*c;

			}else{

				sum += (y-x)*b;

			}

		}

	}else{//单买更优惠 

		sum = x*a + y*b; 

	}

	printf("%d\n", sum);

	

	return 0;

}