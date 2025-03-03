#include<cmath>

#include<math.h>

#include<ctype.h>

#include<algorithm>

#include<bitset>

#include<cassert>

#include<cctype>

#include<cerrno>

#include<cfloat>

#include<ciso646>

#include<climits>

#include<clocale>

#include<complex>

#include<csetjmp>

#include<csignal>

#include<cstdarg>

#include<cstddef>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<ctime>

#include<cwchar>

#include<cwctype>

#include<deque>

#include<exception>

#include<fstream>

#include<functional>

#include<iomanip>

#include<ios>

#include<iosfwd>

#include<iostream>

#include<istream>

#include<iterator>

#include<limits>

#include<list>

#include<locale>

#include<map>

#include<memory>

#include<new>

#include<numeric>

#include<ostream>

#include<queue>

#include<set>

#include<sstream>

#include<stack>

#include<stdexcept>

#include<streambuf>

#include<string>

#include<typeinfo>

#include<utility>

#include<valarray>

#include<vector>

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

using namespace std;

struct node

{

	int x,y;

}a[100010];

int n,m;

int f[200010][2];

bool cmp(node x,node y)

{

	return x.x<y.x;

}

int main()

{

	scanf("%d%d",&n,&m);

	for (int i=1;i<=m;i++)

	{

		scanf("%d%d",&a[i].x,&a[i].y);

	}

	sort(a+1,a+m+1,cmp);

	for (int i=1;i<=m;i++)

	{

		int t=a[i].y;

		f[t][1]=max(f[t+1][1]+1,f[t][1]);

		f[t+1][0]=max(f[t][0]+1,f[t+1][0]);

	}

	printf("%d",f[1][0]+f[1][1]+1);

	for (int i=2;i<=n;i++)

	{

		printf(" %d",f[i][0]+f[i][1]+1);

	}

	printf("\n");

    return 0;

}