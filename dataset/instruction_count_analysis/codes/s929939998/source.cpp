#include <cstdio>

#include <algorithm>

#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

int num[30];

char ar[105];



int main()

{

    while(~scanf(" %s",ar)){

        int len = strlen(ar);

        for(int i=0;i<len;i++){

            num[ar[i]-'a']++;

        }

        bool flag = true;

        for(int i=0;i<26;i++){

            if(num[i]%2 != 0){

                flag = false;

                break;

            }

        }

        if(flag){

            printf("Yes\n");

        }

        else

            printf("No\n");



    }

    return 0;

}
