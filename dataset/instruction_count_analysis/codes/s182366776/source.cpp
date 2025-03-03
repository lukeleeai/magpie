#include <stdio.h>



constexpr char* S_OUT[31] = {

    "0\n", "1\n", "2\n", "3\n", "4\n", "5\n", "6\n", "7\n", "8\n", "9\n", "10\n",

    "11\n", "12\n", "13\n", "14\n", "15\n", "16\n", "17\n", "18\n", "19\n", "20\n",

    "21\n", "22\n", "23\n", "24\n", "25\n", "26\n", "27\n", "28\n", "29\n", "30\n"

};



constexpr unsigned int InputSize = 3e6;

constexpr unsigned int OutputSize = 3e5;

char Input[InputSize];

char* pointer = Input;

char Output[OutputSize];

char* m_buffer = Output;



inline unsigned int getInt(void){

    unsigned int res = 0;

    do{ res = 10 * res + (*(pointer++) - '0'); } while(*pointer >= '0');

    return res;

}



inline void out(int v){

    char* str = S_OUT[v];

    while(*str) *(m_buffer++) = *(str++);

}



unsigned int n;

unsigned int N;

constexpr unsigned int SIZE = (1U << 19) + 1;

unsigned int data[2 * SIZE];



inline void set(void){

    n = getInt(); N = 1U << (31 - __builtin_clz(n)); while(N < n) N <<= 1;

    ++pointer; // \n

    unsigned int i, j;

    for(i = 0, j = N; i < n; ++i, ++j) data[j] = 1U << (*(pointer++) - 'a');

    for(i = N - 1; i ; --i) data[i] = data[i << 1] | data[(i << 1) | 1U];

}



inline void query(void){

    pointer += 3;

    if(*(pointer - 2) == '1'){

        unsigned int index = getInt() - 1;

        unsigned char idx = *((++pointer)++) - 'a';

        data[index += N] = 1U << idx;

        while(index >>= 1) data[index] = data[index << 1] | data[(index << 1) | 1U];

    }

    else{

        unsigned int l = getInt() + N - 1; pointer++;

        unsigned int r = getInt() + N;

        unsigned int res = 0;

        while(l < r){

            if(l & 1) res |= data[l++]; l >>= 1;

            if(r & 1) res |= data[--r]; r >>= 1;

        }

        out(__builtin_popcount(res));

    }

}



int main(void){

    fread(Input, sizeof(char), InputSize, stdin);

    set(); ++pointer;

    unsigned int q = getInt();

    while(q--) query();

    setvbuf(stdout, 0, _IONBF, 0);

    fputs(Output, stdout);

    return 0;

}