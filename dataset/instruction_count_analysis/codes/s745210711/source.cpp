#include <cstdio>

#include <algorithm>



using std::min;



const int MAXN=100005;



int main()

{

    int N,K,diffs=0;

    char str[MAXN];



    scanf("%d%d%s",&N,&K,str);



    for (int i=1;i<N;++i)

        if (str[i]!=str[i-1]) diffs++;

    printf("%d",min(N-1-diffs+2*K,N-1));



    return 0;

}
