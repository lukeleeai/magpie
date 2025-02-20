#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char s[100001];
    int k;
    scanf("%d %s", &k, s);
    
    int len = strlen(s);
    if (len > k) {
        printf("%.*s...\n", k, s);
    } else {
        puts(s);
    }
}
