#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include<algorithm>

using namespace std;

int main()

{

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

   if(b-a == c-b) printf("YES");

   else printf("NO");

    return 0;

}