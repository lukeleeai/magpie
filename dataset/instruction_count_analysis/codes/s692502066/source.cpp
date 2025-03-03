#include <cstdio>

using namespace std;



int main(){

    int n,a,cnt=0;

    scanf("%d",&n);

    for(int i=0; i<n; i++){

        scanf("%d",&a);

        while(1){

            if(a&1){

                break;

            }

            cnt++;

            a>>= 1;

        }

    }

    printf("%d\n",cnt);

}