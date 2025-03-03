#include <stdio.h>

#include <string.h>



int cnt[26] = {};

char s[100005];



int main() {

    scanf("%s", s);

    for(int i = 0; s[i]; i++)

        cnt[s[i] - 'a']++;

    for(int i = 0; i < 26; i++) {

        if(!cnt[i]) {

            printf("%c\n", i + 'a');

            return 0;

        }

    }

    puts("None");

    return 0;

}
