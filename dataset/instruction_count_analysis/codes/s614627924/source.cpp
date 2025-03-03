#include <cstdio>

#include <algorithm>

#include <cmath>

#include <cstring>

#include <iostream>

#include <ctime>

#include <map>

#include <queue>

#include <cstdlib>

#include <string>

#include <climits>

#include <set>

#include <vector>

using namespace std;

inline int read(){

	int k=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}

	return k*f;

}

bool f[20010];

int main()

{

	int n=read();f[0]=1;

	for(int i=1;i<=n;i++){

		int x=read();

		for(int j=10000;j>=0;j--)f[j+x]|=f[j];

	}

	int ans=0;

	for(int i=10000;i>=0;i--)if(i%10!=0&&f[i]){ans=i;break;}

	printf("%d",ans);

	return 0;

}