#include<cstdio>

using namespace std; 

int main()

{

    int a;

    scanf("%d\n",&a);

    if(a<2)  {printf("1\n"); return 0;}

    if(a<4)  {printf("2\n"); return 0;}

    if(a<8)  {printf("4\n"); return 0;}

    if(a<16) {printf("8\n"); return 0;}

    if(a<32) {printf("16\n");return 0;}

    if(a<64) {printf("32\n");return 0;}

    if(a<128){printf("64\n");return 0;}

}