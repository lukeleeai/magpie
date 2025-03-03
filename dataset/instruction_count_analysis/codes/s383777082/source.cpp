#pragma GCC optimize("Ofast")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <cstdio>

#include <cstdint>

using namespace std;



uint_fast16_t d;

uint_fast32_t M = 0;

uint_fast64_t c, sd = 0, sc = 0;

constexpr int cm = 1 << 22;

char buff[cm], *ci;

int main() {

	fread_unlocked(buff, 1, cm, stdin); ci = buff;

    while(*ci>47) M = (M<<1) + (M<<3) + *ci++ - 48;

    while(M--) {

        c = 0;

        d = *++ci - 48;

        ++ci;

        while(*++ci>47) c = (c<<1) + (c<<3) + *ci - 48;

        sc += c;

        sd += c * d;

    }

    printf("%lld", --sc + --sd / 9);

	return 0;

}
