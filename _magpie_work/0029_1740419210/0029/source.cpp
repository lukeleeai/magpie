#include <iostream>
#include <cstdio>
#include <cstring>
#include <array>
using namespace std;

inline long long int gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

inline long long int lcm(long long int a, long long int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    array<long long int, 3> a, m, c = {0}, p;
    while (true) {
        memset(c.data(), 0, sizeof(c));
        // Reading input using a single scanf to increase speed
        if (scanf("%lld %lld %lld %lld %lld %lld", &a[0], &m[0], &a[1], &m[1], &a[2], &m[2]) != 6 || !a[0]) break;

        for (int i = 0; i < 3; i++) {
            p[i] = a[i] % m[i]; // Start with the correct modulo
            c[i] = 1; // Initialize count
            while (p[i] != 1) {
                p[i] = (a[i] * p[i]) % m[i];
                c[i]++;
            }
        }
        
        long long int first_lcm = lcm(c[0], c[1]);
        printf("%lld\n", lcm(first_lcm, c[2]));
    }
    return 0;
}
