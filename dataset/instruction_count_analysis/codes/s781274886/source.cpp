#include <cstdio>

#include <cstring>

#include <cmath>

#include <queue>

#include <set>

#include <map>

#include <algorithm>

using namespace std;

char num[20];

int main()

{

	while(~scanf("%s",num))

	{

		int len=strlen(num);

		int i=len-1;

		for(;i>=0;i--)

		{

			if(num[i]!='9') break;

		}

		if(i==-1) printf("%d\n",len*9);

		else if(i==0) printf("%d\n",(len-1)*9+num[0]-'0');

		else printf("%d\n",(len-1)*9+num[0]-'0'-1);

	}

	return 0;

} 