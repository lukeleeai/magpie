#include <cstdio>

#include <vector>

#include <algorithm>



int N;



int main(){



    while(1){

start:

        scanf("%d",&N);



        if(N == 0)break;

        int cnt = 0;

        bool flag = false;



        for(int i=0;i<N;i++){

            int tmp;

            scanf("%d",&tmp);

            if(tmp != 0)cnt++;

            if(tmp > 1) flag = true;

        }

        if(N == 1 && flag){

            printf("2\n");

            goto start;

        }

        if(!flag){

            printf("NA\n");

            goto start;

        }



        int ans = cnt + 1;



        printf("%d\n",ans);

    }

    return 0;

}