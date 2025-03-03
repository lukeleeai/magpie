#include<cstdio>

using namespace std;

const int maxn=5e5+5;

char ch,s[maxn];

int n,bit[maxn][30],opt,l,r,t;

int lowbit(int x){

    return x&(-x);

}

void update1(int x,int y){

//    printf("sssssssss%d %dssssssssss\n",x,y);

//    printf("1111");

    while(x<=n){

//           printf("444444");

        bit[x][y]++;

//        printf("1111");

        x=x+lowbit(x);

//        printf("1111");

    }

}

void update2(int x,int y){

    while(x<=n){

        bit[x][y]--;

        x=x+lowbit(x);

    }

}

int query(int x,int i){

    int ans=0;

    while(x>0){

        ans+=bit[x][i];

        x=x-lowbit(x);

    }

    return ans;

}

int main(){

    scanf("%d %s %d",&n,s+1,&t);

//    printf("222");

    for(int i=1;i<=n;i++){

//       printf("33333");

        update1(i,s[i]-'a');

    }

    while(t--){

        scanf("%d",&opt);

        if(opt==1){

            scanf("%d %c",&l,&ch);

            update2(l,s[l]-'a');

            update1(l,ch-'a');

            s[l]=ch;

        }else{

            scanf("%d %d",&l,&r);

            int ans=0;

            for(int i=0;i<=25;i++){

                if(query(r,i)-query(l-1,i)){

                    ans++;

                }

            }

            printf("%d\n",ans);

        }

    }

    return 0;

}
