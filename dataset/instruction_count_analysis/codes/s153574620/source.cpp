#include<cstdio>

#include<vector>

#include<algorithm>



using namespace std;

const int maxn=105;

int v[maxn],plate[maxn];



int main(){

    int n,k,r;

    scanf("%d %d",&n,&k);

//    vector<int> v(n),plate(n);

    for(int i=0;i<n;++i){

        scanf("%d",&v[i]);

    }

    r=min(n,k);

    int ans=0;

    for(int A=0;A<=r;++A){

        for(int B=0;B<=r-A;++B){

            int i,j;

            for(i=0;i<A;++i){

                plate[i]=v[i];

            }

            for(j=0;j<B;++j){

                plate[i+j]=v[n-1-j];

            }

            sort(plate,plate+A+B);

            i=0;

            while(i<k-(A+B)&&plate[i]<0){

                ++i;

            }

            int tmp=0;

            while(i<A+B){

                tmp+=plate[i++];

            }

            ans=max(ans,tmp);

        }

    }

    printf("%d\n",ans);

    return 0;

}
