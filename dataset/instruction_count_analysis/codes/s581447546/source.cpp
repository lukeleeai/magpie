#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cmath>

#include <limits>



using ull =  long long;

using namespace std;



const int MAX_N = 2 * 10e5 + 5;

ull arr[MAX_N];//start from 1, arr[1] = 0

int n;

int pre_l, pre_r;



ull solve(int mid) {

    ull pre_diff = numeric_limits<ull>::max();

    ull curr_diff;

    int l = mid - 1, r = n - 1;

    for (int i = pre_l; i < mid; ++i) {

        curr_diff = abs(arr[mid] - arr[i] - arr[i]);

        if (curr_diff >= pre_diff) {

            l = i - 1;

            break;

        }

        pre_diff = curr_diff;

    }

    pre_diff = numeric_limits<ull>::max();

    for (int j = pre_r; j < n; ++j) {

        curr_diff = abs(arr[n] - arr[j] - (arr[j] - arr[mid]));

        if (curr_diff >= pre_diff) {

            r = j - 1;

            break;

        }

        pre_diff = curr_diff;

    }

    ull sum[4];

    sum[0] = arr[l];

    sum[1] = arr[mid] - arr[l];

    sum[2] = arr[r] - arr[mid];

    sum[3] = arr[n] - arr[r];

    ull mi, ma;

    ma = *max_element(sum, sum + 4);

    mi = *min_element(sum, sum + 4);

    pre_l = l;

    pre_r = r;

    return ma - mi;

}



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {

        scanf("%lld", arr + i);

        arr[i] += arr[i - 1];

    }

    ull mi = numeric_limits<ull>::max();

    pre_l = 1;

    pre_r = 3;

    for (int i = 2; i <= n - 2; ++i) {

        ull ans = solve(i);

        mi = mi < ans ? mi : ans;

    }

    printf("%lld", mi);

    return 0;

}