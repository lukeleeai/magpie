#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>



using namespace std;

int cnt4,cnt2,n;

int a;



int main()

{

    scanf("%d",&n);

    for(int i=0;i<n;i++)

    {

        scanf("%d",&a);

        if(a%4==0)

            cnt4++;

            else if(a%2==0)

                cnt2++;

    }

    if(cnt2+cnt4*2<n-1)

        printf("No\n");

        else if(cnt4*2+cnt2==n-1&&cnt2!=0)

            printf("No\n");

            else

                printf("Yes\n");

    return 0;

}