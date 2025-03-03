#include<cstdio>

#include<algorithm>

using namespace std;



int main(){

    int A,B,C,Ans=0;

    scanf("%d%d%d",&A,&B,&C);

    int Max1=max(A,max(B,C));

    int Max2;

    if(A==Max1) Max2=max(B,C);

    else if(B==Max1) Max2=max(A,C);

    else if(C==Max1) Max2=max(A,B);

    int Max3=A+B+C-Max1-Max2;

    int tmp1=Max1-Max2;

    Ans+=tmp1,Max3+=tmp1,Max2+=tmp1;



    if((Max1-Max3)%2) Ans+=(Max1-Max3)/2+2;

    else Ans+=(Max1-Max3)/2;

    printf("%d",Ans);

}

/*

Sample Input 1

2 5 4

Sample Output 1

2



Sample Input 2

2 6 3

Sample Output 2

5



Sample Input 3

31 41 5

Sample Output 3

23

*/
