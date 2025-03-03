#include<cstdio>

#include<algorithm>

using namespace std;

const int inf=0x3f3f3f3f;

int h,w,k,a[20][1010],pre[20][1010],flag,ans=inf;

char ch;

int main(){

    scanf("%d %d %d",&h,&w,&k);

    for(int i=1;i<=h;i++){

        for(int j=1;j<=w;j++){

            scanf(" %c",&ch);

            pre[i][j]=pre[i][j-1]+ch-'0';

        }

    }

    for(int state=0;state<(1<<h-1);state++){

        int last=0,sum=0,cnt=0,flag=1;

        for(int j=1;j<=w;j++){

            for(int i=1;i<=h;i++){

                sum=sum+pre[i][j]-pre[i][last];

//                printf("%d ",sum);

                if(sum>k){

                    if(j-last==1){//只有一列不能再切不满足条件

                        flag=0;

                        break;

                    }

                    i=0,sum=0,last=j-1;//第二轮循环再来一次

                    cnt++;

                }

                if(i==h||state&(1<<(i-1))){

                    sum=0;

                }

            }

//            printf("\n");

            if(!flag){

                break;

            }

        }

        if(flag){

            ans=min(ans, __builtin_popcountl(state)+cnt);

        }

    }

    printf("%d\n",ans);

    return 0;

}
