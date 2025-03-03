#include <cstdio>
#include <cmath>
using namespace std;

void problemOne() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int sum = a + b;
        int intLength = (sum == 0) ? 1 : (int)log10(sum) + 1;
        printf("%d\n", intLength);
    }
}

int main() {
    problemOne();
}
