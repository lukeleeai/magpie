#include<cstdio>

#include<cstring>

using namespace std;

const int maxn = 1e5 + 7;

char s[maxn];

int main(){

    scanf("%s", s+1);

    int len = strlen(s+1);

    if(s[1] != '1' || s[len] != '0'){

        printf("-1\n");

        return 0;

    }

    for(int i = 1; i <= len/2; ++i){

        if(s[i] != s[len-i]){

            printf("-1\n");

            return 0;

        }

    }

    int record = -1;

    for(int i = len/2; i >= 1; --i){

        if(s[i] == '1'){

            record = i;

            printf("%d %d\n", i, i+1);

            for(int j = i+2; j <= len; ++j){

                printf("%d %d\n", i+1, j);

            }

            break;

        }

    }

    for(int i = record-1; i >= 1; --i){

        printf("%d %d\n", record, i);

        if(s[i] == '1'){

            record = i;

        }

    }

}
