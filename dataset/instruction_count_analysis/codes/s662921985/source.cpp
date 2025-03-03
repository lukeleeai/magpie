#include<iostream>

#include<cstring>

#include<cstdlib>

using namespace std;

int maps[1005][1005];

int main() {

	int h,w,a,b;

	cin>>h>>w>>a>>b;

	memset(maps,0,sizeof(maps));

	for(int i=1; i<=b; i++) {

		for(int j=a+1; j<=w; j++) {

			maps[i][j]=1;

		}

	}

	for(int i=b+1; i<=h; i++) {

		for(int j=1; j<=a; j++) {

			maps[i][j]=1;

		}

	}

	for(int i=1; i<=h; i++) {

		for(int j=1; j<=w; j++)cout<<maps[i][j];

		cout<<'\n';

	}

	return 0;

}