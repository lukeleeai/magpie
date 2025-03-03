#include <cstdio>

#include <algorithm>

 

using namespace std;

 

int main(void) {

    int n, k, x, y;

    scanf("%d %d %d %d", &n, &k, &x, &y);

 

    printf("%d\n", min(k, n)*x + max(0, n-k)*y);

    return 0;

}
