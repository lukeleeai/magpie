#include<iostream>

#include<cstdio>

#include<algorithm>

#define reg register

#define ios ios::sync_with_stdio(false)

using namespace std;

int t[101],p[101];

int main() 

{

	ios;string s1,s2;cin>>s1;s2=s1;

	reverse(s2.begin(),s2.end());//交换函数abc->cba //orz%%%dalao

	int l=s2.length();

	for(reg int i=0;i<=l-1;i++)

	{

		if(s2[i]=='b'){s2[i]='d';continue;}

		if(s2[i]=='d'){s2[i]='b';continue;}

		if(s2[i]=='p'){s2[i]='q';continue;}

		if(s2[i]=='q'){s2[i]='p';continue;}

	}

	if(s1==s2)puts("Yes");

	else	puts("No");

    return 0;

}