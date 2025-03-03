

#include<cstdio>

#include<queue>

#include<cstring>

#include<cmath>

using namespace std;

const int B = 300000+10;

const int N = 10000+10;

const int P = 26    +100;

char a[B];



int main()

{

    int num[P];

    while(scanf("%s",a)==1)

    {

        memset(num,0,sizeof num);

        int len=strlen(a);

        for(int i=0;i<len;i++)

        {

            num[a[i]-'a']++;



        }

        int pos=-1;

        for(int i=0;i<26;i++)

        {

            if(num[i]==0)

            {

                pos=i;

                break;

            }

        }



        if(pos==-1)

        {

            printf("None\n");

        }

        else

        {

            printf("%c\n",'a'+pos);

        }



    }

return 0;

}