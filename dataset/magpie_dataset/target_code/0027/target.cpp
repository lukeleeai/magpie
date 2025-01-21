#include <cstdio>



using namespace std;



int main() {

    char s[16], t[16]={};

    scanf("%s", s);



    int j=0;

    for (int i=0; s[i]; ++i) {

        switch (s[i]) {

            case 'B':

                if (j)

                    t[--j] = '\0';



                break;

            default:

                t[j++] = s[i];

        }

    }



    printf("%s\n", t);

    return 0;

}
