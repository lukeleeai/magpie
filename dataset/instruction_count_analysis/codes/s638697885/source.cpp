#include <iostream>

#include <vector>

#include <algorithm>



#define MAX 100000



using namespace std;



int main() {

    int n, v;

    scanf("%d", &n);

    vector< vector<int> > d(2, vector<int>(MAX + 1));

    for (int i = 0; i < n; ++i) {

        scanf("%d", &v);

        ++d.at(i % 2).at(v);

    }

    auto a = max_element(d.front().begin(), d.front().end()), b = max_element(d.back().begin(), d.back().end());

    if (a - d.front().begin() != b - d.back().begin()) printf("%d\n", n - *a - *b);

    else {

        int va = *a, vb = *b;

        *a = 0, *b = 0;

        a = max_element(d.front().begin(), d.front().end()), b = max_element(d.back().begin(), d.back().end());

        printf("%d\n", min(n - va - *b, n - vb - *a));

    }

    return 0;

}
