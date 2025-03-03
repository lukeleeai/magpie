#include <stdio.h>



int main(){

    char arr[20];

    scanf ("%[^\n]", arr);

    for (int i = 0; arr[i] != '\0'; i++)

        if (arr[i] == ',') arr[i] = ' ';

    puts (arr);

}
