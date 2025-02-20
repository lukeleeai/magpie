#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int k;
    char s[100005];
    scanf("%d %s", &k, s);
    
    int len = strlen(s);
    if (len > k) {
        for (int i = 0; i < k; i++)
 printf("%c", s[i]);
        printf("...\n");
    } else {
        printf("%s\n", s);
    }
}
