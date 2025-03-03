#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

char dt[30],l,r,s;

int n,t[4],k,f,m;

int main(){

	scanf("%d",&n);

	memset(t,0,sizeof(t));

	f=0;

	while(n--){

		scanf("%s",dt);

		s=strlen(dt);

		l=dt[0];

		r=dt[s-1];

		for(int i=1;i<s;i++)if(dt[i]=='B'&&dt[i-1]=='A')f++;

		k=0;

		if(l=='B')k++;

		if(r=='A')k+=2;

		t[k]++;

	}

//		printf("%d\n",f);

	m=t[1]+t[2];

	k=min(t[2],min(t[1],t[3]));

	f+=k<<1;

	t[1]-=k;t[2]-=k;t[3]-=k;

//	printf("%d %d %d\n",t[1],t[2],t[3]);

//	printf("%d\n",f);

	f+=min(t[1],t[2]);

//	printf("%d\n",min(t[1],t[2]));

	if(m)f+=t[3];

	else f+=max(0,t[3]-1);

	printf("%d\n",f);

}