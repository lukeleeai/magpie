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

const int N=500010;

int n;

map<int,int> mp;

int main()

{

	scanf("%d",&n);

	int now=1,cnt=0;

	while (n--)

	{

		int x;

		scanf("%d",&x);

		if (x<now)

		{

			printf("No\n");

			continue;

		}

		printf("Yes\n");

		while (mp[x]>0 && x>0)

		{

			mp[x]=0;

			x--;

			cnt--;

		}

		mp[x]=1;

		cnt++;

		while (mp[now]>0 && now<N)

		{

			now++;

		}

		now=min(now,cnt);

		if (x==0)

		{

			now=1e9;

		}

	}

    return 0;

}