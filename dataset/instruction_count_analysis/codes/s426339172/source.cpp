/*

ID: espr1t

TASK: 

KEYWORDS: 

*/



#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <string>



using namespace std;



const int MAX = 1024;



int ans;

int limit;



void recurse(long long num, int mask) {

    if (num > limit)

        return;

    if ((mask & 7) == 7)

        ans++;

    recurse(num * 10 + 3, mask | 1);

    recurse(num * 10 + 5, mask | 2);

    recurse(num * 10 + 7, mask | 4);

}



int main(void) {

	// in = fopen("C.in", "rt");

	

	scanf("%d", &limit);

	

	recurse(0, 0);

	printf("%d\n", ans);

	

	return 0;

}
