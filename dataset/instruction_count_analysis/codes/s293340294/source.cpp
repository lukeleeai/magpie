#include<stdio.h>

int main()

{

    char s[200];



    scanf("%s",s);



    int len=0;



    for(int i=0; s[i]!=0;i++)

    len++;



    int count=0;

    for(int i=0,j=(len-1);i<=j;i++,j--)

    {

        if(s[i]!=s[j])

        count++;

    }



    printf("%d",count);

    return 0;

}
