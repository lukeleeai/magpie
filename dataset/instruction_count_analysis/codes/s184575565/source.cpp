#include <stdio.h>

int n,ans;

char s[30000];

int pos[10][30000],size[10];

bool ok(int i,int j,int k){

    if(size[i]==0||size[j]==0||size[k]==0) return false;

    int pivot=-1;

    for(int a=0;a<size[j];a++){

        if(pos[j][a]>pos[i][0]){

            pivot=pos[j][a];

            break;

        }

    }

    if(pivot==-1) return false;

    for(int b=0;b<size[k];b++){

        if(pos[k][b]>pivot){

            return true;

        }

    }

    return false;

}

int main(){

    for(int i=0;i<=9;i++){

        size[i]=0;

    }

    scanf("%d",&n);

    scanf("%s",&s);

    for(int i=0;i<n;i++){

        int num=s[i]-'0';

        pos[num][size[num]]=i;

        size[num]++;

    }

    for(int i=0;i<=9;i++){

        for(int j=0;j<=9;j++){

            for(int k=0;k<=9;k++){

                if(ok(i,j,k)) ans++;

            }

        }

    }

    printf("%d\n",ans);

}