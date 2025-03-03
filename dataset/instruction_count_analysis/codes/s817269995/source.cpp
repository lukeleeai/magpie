#include <stdio.h>

#include <math.h>

int main()

{

    int n,sum=0;

    scanf("%d",&n);

    int ch[55];

    for(int i=0;i<n;i++)

        scanf("%d",&ch[i]);

    for(int i=0;i<n;i++)

    {

        for(int j=i+1;j<n;j++)

        {

            sum=sum+ch[i]*ch[j];

        }

    }

    printf("%d\n",sum);

    return 0;

}
