# include "cstdio"

# include "iostream"



using namespace std;



inline int n_lowbit(int x){    //取出含有质因子2的个数 

    int count=0;

    while(x){

        if(x&1){

            return count; 

        }

        count++; 

        x>>=1; 

    }

    return count; 

} 



int

    ans, //记录答案 

    N, 

    a; 



int main(){

    scanf("%d",&N);

    while(N--){

        scanf("%d",&a);

        ans+=n_lowbit(a); //更新答案 

    }

    printf("%d",ans); 

    return 0; 

} 