#include <cstdio>

#include <algorithm>

using namespace std;

struct node{

	int l,r;

}a[1000005];

int tot;

char s[1000005];

int cmp(node a,node b){

	return a.l-a.r>b.l-b.r;

}

int main(){

	int n,ri,le;

	int i,j;

	le=ri=0;

	scanf("%d",&n);

	for(i=1;i<=n;i++){

		int l=0,r=0;

		scanf("%s",s+1);

		for(j=1;s[j];j++)

			if(s[j]=='(')l++;

			else if(s[j]==')'){

				if(l)l--;

				else r++;

			}

		if(!l&&r)ri+=r;

		else if(l&&!r)le+=l;

		else if(l&&r)a[++tot]=(node){l,r};	

	}

	sort(a+1,a+1+tot,cmp);

	for(int i=1;i<=tot;i++){

		if(le<a[i].r)

			return puts("No"),0;

		le-=a[i].r,le+=a[i].l;

	}

	if(le!=ri)puts("No");

	else puts("Yes");

	return 0;

}