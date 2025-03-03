#include <cstdio>

#include <cstring>



using namespace std;



int main()

{

  char s[100015];

  int len;

  char c;

  int i;

  bool begin;



  fgets(s, 100015, stdin);

  len = strlen(s) - 1;



#if 0

  printf("string is %s\n", s);

  printf("len %d\n", len);

#endif



  begin = true;

  

  for (i = 0; i<len; i++) {

    if (begin) {

      if (s[i] == 'd') {

        if ((s[i+1] != 'r') ||

            (s[i+2] != 'e') ||

            (s[i+3] != 'a') ||

            (s[i+4] != 'm')) {

           printf("NO\n");

           return 0;

        }

        

        if ((s[i+5] == 'e') &&

            (s[i+6] == 'r') &&

            (s[i+7] != 'a')) {

          i+=6;

        } else {

          i+=4;

        }

      } else if (s[i] == 'e') {

        if ((s[i+1] != 'r') ||

            (s[i+2] != 'a') ||

            (s[i+3] != 's') ||

            (s[i+4] != 'e')) {

           printf("NO\n");

           return 0;

        }

        if (s[i+5] == 'r') {

          i+=5;

        } else {

          i+=4;

        }



      } else {

        printf("NO\n");

        return 0;

      }

    }

  }



  printf("YES\n");



  return 0;

}
