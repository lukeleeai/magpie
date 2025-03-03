#include<cstdio>

using namespace std;

int main(){

    int a,b;

    scanf("%d%d",&a,&b);

    if(a>0)

        printf("Positive");             

    else if(b>=0)

        printf("Zero");          

    else if((a&1)^(b&1))

        printf("Positive");

    else 

        printf("Negative");

    return 0;

}