#include<iostream>

#include<cstdio>

using namespace std;

char s[4]={ 'R', 'Y', 'G', 'B' };

int main()

{

	int h,w,d;

	cin>>h>>w>>d;

	int x,y;

	for(int i=1;i<=h;i++,putchar('\n'))

	for(int j=1;j<=w;j++)

	{

		x=i+j+w,y=i-j+w;

		putchar(s[((x/d)&1)*2+((y/d)&1)]);

	}

	return 0;

}