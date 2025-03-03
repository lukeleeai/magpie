#include <cstdio>

#include <string>



using namespace std;



int main() {

    char buf[131072];

    scanf("%s", buf);

    string s(buf);

    size_t ub=s.length();

    s += '$';



    for (size_t i=0; i<ub; ++i)

        for (size_t j=1; j<=2; ++j)

            if (s[i] == s[i+j]) {

                printf("%llu %llu\n", i+1, i+j+1);

                return 0;

            }



    printf("-1 -1\n");

    return 0;

}
