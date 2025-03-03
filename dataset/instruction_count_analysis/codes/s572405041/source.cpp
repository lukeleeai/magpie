#include <iostream>

#include <algorithm>

#include <cstdio>

#include <cstring>

#define M 300005

using namespace std;

int main()

{

    int n;

    char A[M];

    int B[M];

    while(scanf("%d",&n)!=EOF)

    {

        memset(A,'\0',sizeof(A));

        scanf("%s",A);



        for(int i=0,cnt=0;i<n;i++)

        {

            B[i] = cnt;

            if(A[i] == 'W') cnt++;

        }

        for(int i=n-1,cnt=0;i>=0;i--)

        {

            B[i] = B[i] + cnt;

            if(A[i] == 'E') cnt++;

        }

        sort(B,B+n);

        printf("%d\n",B[0]);

    }

    return 0;

}
