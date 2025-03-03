#include<cstdio>

#include<set>

#include<algorithm>

using namespace std;

const int maxn=5e5+5;

char s[maxn],ch;

set<int> pos[26];

int n,t,opt,x,y;

int main(){

    scanf("%d %s %d",&n,s+1,&t);

    for(int i=0;i<=25;i++){

        pos[i].insert(n+1);//防止二分为空

    }

    for(int i=1;i<=n;i++){//放入相应的set

        pos[s[i]-'a'].insert(i);

    }

    while(t--){

        scanf("%d",&opt);

        if(opt==1){

            scanf("%d %c",&x,&ch);

            if(s[x]!=ch){

                pos[s[x]-'a'].erase(x);//删除

                pos[ch-'a'].insert(x);//加入

                s[x]=ch;

            }

        }else{

            scanf("%d %d",&x,&y);

            int ans=0;

            for(int i=0;i<=25;i++){

                if(*pos[i].lower_bound(x)<=y){

                    ans++;

//                    printf("111111111 ");

                }

            }

            printf("%d\n",ans);

        }

    }

    return 0;

}
