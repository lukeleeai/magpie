#include <stdio.h>

#include <math.h>

#include <iostream>

#include <string.h>

#include <limits.h>

#include <string>

#include <vector>

#include <algorithm>

#include <map>

#include <set>



#ifndef ULLONG

typedef unsigned long long ULLONG;

#endif

#ifndef LLONG

typedef long long LLONG;

#endif

template <class _T> static _T tp_abs(const _T& a) {

	return ((a < 0) ? (a * -1) : a);

}

template <class _T> static _T tp_min(_T a, _T b) {

	return a < b ? a : b;

}

template <class _T> static _T tp_max(_T a, _T b) {

	return a > b ? a : b;

}

template<class _T> static void get1int(_T& a) {

	const char* fmt = " %d";

	if (sizeof(_T) == sizeof(long long)) {

		fmt = " %lld";

	}



	if (scanf(fmt, &a) < 0) {

		printf("g1int Error\n");

	}

}

template<class _T> static void get2int(_T& a, _T& b) {

	const char* fmt = " %d %d";

	if (sizeof(_T) == sizeof(long long)) {

		fmt = " %lld %lld";

	}



	if (scanf(fmt, &a, &b) < 0) {

		printf("g2int Error\n");

	}

}

template<class _T> static void get3int(_T& a, _T& b, _T& c) {

	const char* fmt = " %d %d %d";

	if (sizeof(_T) == sizeof(long long)) {

		fmt = " %lld %lld %lld";

	}



	if (scanf(fmt, &a, &b, &c) < 0) {

		printf("g3int Error\n");

	}

}

static void getstring(char* buff) {

	if (scanf(" %s", buff) < 0) {

		printf("getstr error!\n");

	}

}

template <class _T> static _T tp_pow(int base, int exp)

{

	_T ans = 1;



	for (int i = 0; i < exp; i++) {

		ans *= base;

	}

	return ans;

}



static void C_task();



int main()

{

	C_task();



	fflush(stdout);

	return 0;

}



static void C_task()

{

	int L, R;

	get2int(L, R);



	LLONG minMod = 2020;

	for (LLONG i = L; i < std::min(R, L + 2021); i++) {

		for (LLONG j = i + 1; j <= std::min(R, L + 2021); j++) {

			LLONG tmp = (i * j) % 2019;

			minMod = tp_min<LLONG>(tmp, minMod);

		}

	}



	printf("%lld\n", minMod);

}
