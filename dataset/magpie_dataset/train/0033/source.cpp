#include <vector>

#include <algorithm>

#include <string>

#include <map>

#include <set>

#include <queue>

#include <cstring>

#include <deque>

#include <cstdio>

#include <cmath>



using namespace std;



#define reep(i,f,t) for(int i=f ; i<int(t) ; ++i)

#define rep(i,n) reep(i, 0, n) 



typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int,int> pii;



int main()

{

	int n;

	while(scanf("%d", &n), n){

		vi nums(n, 0);

		reep(i, 1, n)

			nums[(i*i)%n] |= 1;

		reep(i, 1, (n+1)/2){

			int sum = 0;

			rep(j, n)

				sum += nums[j] & nums[(j+i)%n];

			printf("%d\n", sum * 2);

		}

	}

	

	return 0;

}