#include<stdio.h>

#include<string.h>



int main(void){

    char s[11], t[11];

    scanf("%s %s", s, t);

    puts(strncmp(s, t, strlen(s)) ? "No" : "Yes");

    return 0;

}
