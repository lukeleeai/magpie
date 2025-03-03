#include <stdio.h>

 

int main(){

    char s[21];

    scanf ("%[^\n]", s);

    for (int i = 0; s[i] != '\0'; i++)

        if (s[i] == ',') s[i] = ' ';

    puts (s);

    return 0;

}