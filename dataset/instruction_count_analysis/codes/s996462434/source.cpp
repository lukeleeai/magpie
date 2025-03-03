#include<stdio.h>

#include<string.h>

char a[100000010];

int main(){

    scanf("%s",a);

    int t=1;

    for(int i=0;i<=(strlen(a)-1)/2;i++){

        if((a[i]=='d'&&a[strlen(a)-i-1]=='b')||(a[i]=='b'&&a[strlen(a)-i-1]=='d')||(a[i]=='q'&&a[strlen(a)-i-1]=='p')||(a[i]=='p'&&a[strlen(a)-i-1]=='q'));

        else t=0;

    }

    if(t)printf("Yes");

    else printf("No");

}