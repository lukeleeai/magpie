#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long int num1, num2;
    while(scanf("%lld%lld", &num1, &num2) != EOF) {
        long long int gcd = num1, lcm, res = num1 * num2;
        while(num2 != 0) {
            long long int temp = num2;
            num2 = gcd % num2;
            gcd = temp;
        }
        lcm = res / gcd;
        printf("%lld %lld\n", gcd, lcm);
    }
    return 0;
}
