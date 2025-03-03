#include <algorithm>

#include <cstdio>

#include <cstring>

using namespace std;



char s[100];



int main() {

    scanf("%s",s);

    if(s[2]==s[3]&&s[4]==s[5])  printf("Yes");

    else printf("No");

    return 0;

}