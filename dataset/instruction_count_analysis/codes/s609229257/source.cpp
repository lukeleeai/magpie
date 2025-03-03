#include <cstdio>

#include <algorithm>

#include <utility>



using namespace std;



int N,M,H,K;



typedef int start_t;

typedef int end_t;



start_t src[1002];//下っ端と対応する上端

end_t target[1002];//上端と対応する

int scores[1002];

pair<int,int> yokobou[100002];

pair<start_t,start_t> swp[100002];



void init(){

    for(int i=1;i<=N;i++) scanf("%d",scores+i),src[i]=i;

    for(int i=1;i<=M;i++) scanf("%d%d",&yokobou[i].second,&yokobou[i].first);

}



int main(){

    while(scanf("%d%d%d%d",&N,&M,&H,&K)&&N&&M&&H&&K){

        init();

        sort(yokobou+1,yokobou+1+M);

        for(int i=1;i<=M;i++){

            end_t index=yokobou[i].second;

            swp[i].first=min(src[index],src[index+1]);

            swp[i].second=max(src[index],src[index+1]);

            swap(src[index],src[index+1]);

        }



        int sum=0;

        for(int i=1;i<=N;i++) {

            sum+=src[i]<=K?scores[i]:0;

            target[src[i]]=i;

        }



        int ans=sum;

        for(int i=1;i<=M;i++){

            if (swp[i].first<=K&&swp[i].second>K){

                int a=scores[target[swp[i].first]],b=scores[target[swp[i].second]];

                ans=min(ans,sum-a+b);

            }

        }



        printf("%d\n",ans);

    }



    return 0;

}
