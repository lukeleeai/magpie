#include <cstdio>

#include <cstring>



using namespace std;



int main() {

    char s[131072]={};

    scanf("%s", s);

    size_t ub=strlen(s);

    s[ub] = '$';



    for (size_t i=0; i<ub; ++i)

        for (size_t j=1; j<=2; ++j)

            if (s[i] == s[i+j]) {

                printf("%llu %llu\n", i+1, i+j+1);

                return 0;

            }



    printf("-1 -1\n");

    return 0;

}
