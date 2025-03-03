#include<stdio.h>

#include<stdlib.h>

#include<iostream>

#include<algorithm>

#include<string.h>

using namespace std;

typedef struct{

	char str[101];

	int pri;

	int no;

}node;

node p[101];

bool cmp(node a,node b)

{

	if(a.str!=b.str)

    return strcmp(a.str,b.str)<0;

    else

    return a.pri<b.pri;

}

int main()

{

	int n;

	cin>>n;

	for(int i=0;i<n;i++){

		scanf("%s",&p[i].str);

		cin>>p[i].pri;

		p[i].no = i+1;

	}

	

	sort(p, p+n, cmp);

	for(int i=0;i<n;i++)

		for(int j=0;j<n-i-1;j++){

		if(strcmp(p[j].str,p[j+1].str)==0 && p[j].pri<p[j+1].pri)

			swap(p[j],p[j+1]);

	}

	for(int i=0;i<n;i++)

	cout<<p[i].no<<endl;

	return 0;

 } 