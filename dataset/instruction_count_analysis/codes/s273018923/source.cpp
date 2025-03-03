#include<iostream>

#include<cstdio>

using namespace std;

char s[305][305];

int n,ans=0,flag;

int main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++) cin>>s[i];

	for(int k=0;k<n;k++){

		flag=1;

		for(int i=0;i<n&&flag;i++){

			for(int j=0;j<n;j++){

				if(s[i][(j+k)%n]!=s[j][(i+k)%n]){

					flag=0;

					break;

				}

			}

		}

		ans+=n*flag;

	}

	printf("%d\n",ans);

	return 0;

}