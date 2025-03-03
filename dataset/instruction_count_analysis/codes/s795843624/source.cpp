#include"stdc++.h"

#define maxn 505

using namespace std;



int n,x[maxn],c[maxn],a[maxn*maxn];



int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d",&x[i]);

	bool ER = 0;

	for(int i=1;i<=n*n;i++){

		for(int j=1;j<=n;j++) if(x[j] == i){

			c[j] ++;

			if(c[j] != j){

				ER = 1;

			}

			a[i] = j;

			break;

		}

		if(!a[i]){

			int p=0 , lc = n*n+2;

			for(int j=1;j<=n;j++) if(c[j] < j-1){

				if(x[j] < lc){

					lc = x[j];

					p = j;

				}

			}

			if(p){

				a[i] = p ,

				c[p] ++;

			}

		}

		if(!a[i]){

			for(int j=1;j<=n;j++) if(c[j] < n && x[j] < i){

				a[i] = j;

				c[j]++;

				break;

			}

		}

		if(!a[i]){

			ER = 1;

		}

	}

	if(ER){

		puts("No");

	}

	else{

		puts("Yes");

		for(int i=1;i<=n*n;i++) printf("%d%c",a[i]," \n"[i==n*n]);

	}

}