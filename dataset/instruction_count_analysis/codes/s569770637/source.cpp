#include <stdio.h>

#include <algorithm>



constexpr unsigned int N = 2e6;

char buffer[N];

char *ptr = buffer;

constexpr unsigned int S = 5e5;

char Out[2 * S];

char *left = Out + S, *right = Out + S;



int main(void){

    fread(buffer, sizeof(char), N, stdin);

    while('a' <= *ptr) *(right++) = *(ptr++);

    unsigned int q = 0;

    while(*(++ptr) >= '0') q = 10 * q + *ptr - '0';

    bool flag = false;

    while(q--){

        if(*(++ptr) == '1') flag = not flag;

        else{

            if((*(ptr += 2) == '1') ^ flag) *(--left) = *(ptr += 2);

            else *(right++) = *(ptr += 2); 

        }

        ptr++;

    }

    if(flag) std::reverse(left, right);

    fwrite(left, sizeof(char), right - left, stdout);

    return 0;

}