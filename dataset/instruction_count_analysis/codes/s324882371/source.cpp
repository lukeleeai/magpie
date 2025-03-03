#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;



const int maxn = 100010;



char str[maxn];



int main()

{

	//freopen("D.in","r",stdin);

	scanf("%s",str);

	int len = strlen(str);



	int ans = len;

	for (int i=0;i<len-1;i++)

	{

		if (str[i] != str[i+1]) ans = min(ans, max(i+1,len-1-(i+1)+1));

	}



	printf("%d\n",ans);

	return 0;

}
