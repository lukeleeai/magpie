#include <stdio.h>

int main(){

int l,r,d;

scanf("%d %d %d",&l,&r,&d);

printf("%d",(r/d*d-(l+d-1)/d*d)/d+1);

}
