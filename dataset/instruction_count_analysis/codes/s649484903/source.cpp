#include<iostream>

#include<cstdio>

#define mod 1000000007

using namespace std;

int main() {

	int n;

	int a[100500];

	scanf("%d",&n);

	for(int i=1; i<=n; i++) {

		scanf("%d",&a[i]);

	}

	int cnt=1;

	bool b[100500]= {0};

	for(int i=1; i<=n;) {

		if(a[i]!=2) {

			if(b[i]==1) {

				printf("-1");

				break;

			} else {

				cnt++;

				b[i]=1;

				i=a[i];

			}

		}else{

			printf("%d",cnt);

			break;

		}

	}

	return 0;

}