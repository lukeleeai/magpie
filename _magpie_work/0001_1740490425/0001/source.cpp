#include <cstdio>
#include <sstream>

using namespace std;

void problemOne() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        int sum = a + b;
        int intLength = 0;
        while (sum != 0) {
            sum /= 10;
            intLength += 1;
        }
        printf("%d\n", intLength);
    }
}

int main() {
    problemOne();
}
