#include<cstdio>

using namespace std;

int a,b;

int main(){

    scanf("%d%d",&a,&b);

    if(a>0)puts("Positive");               //情况1

    else if(b>=0)puts("Zero");             //情况2

    else if((a&1)^(b&1))puts("Positive");  //情况3

    else puts("Negative");

    return 0;

}