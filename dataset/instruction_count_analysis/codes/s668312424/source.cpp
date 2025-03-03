#include <cstdio>

#include <algorithm>

#include <vector>

#include <map>



using namespace std;



int main() {

    size_t N, T;

    scanf("%zu %zu", &N, &T);



    map<int, size_t> d;

    int min_=1e9+7;

    for (size_t i=0; i<N; ++i) {

        int A;

        scanf("%d", &A);



        if (min_ > A)

            min_ = A;



        if (min_ != A)

            ++d[A-min_];

    }



    printf("%zu\n", d.rbegin()->second);

    return 0;

}
