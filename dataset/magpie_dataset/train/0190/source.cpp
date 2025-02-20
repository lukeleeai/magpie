#include<iostream>

#include<algorithm>

using namespace std;



int main(){

	int a,b;

	int s[5002],t[5002];

	scanf("%d%d",&a,&b);

	for(int i=0;i<a;i++){

		scanf("%d",&s[i]);

	}

	for(int i=0;i<b;i++){

		scanf("%d",&t[i]);

	}



	int ret=0;

	for(int i=0;i<b-ret;i++){

		int p=0,q=i;

		int cnt=0;

		while(1){

			if(s[p]==t[q]){

				cnt++;

				p++;

				q++;

			}

			else {

				p++;

			}

			if(p==a)break;

		}

		ret=max(ret,cnt);

	}



	printf("%d\n",ret);

}