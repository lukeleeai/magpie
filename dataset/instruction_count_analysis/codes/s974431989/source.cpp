#include"stdc++.h"

using namespace std;

int main()

{

    int g,nt,re[100007]={0};

    string q;

    cin>>q;

    for(g=nt=0;q[g];g++){

        if(q[g]=='R')nt++;

        else if(nt)re[g-1]=(nt+1)/2,re[g]=nt/2,nt=0;

    }

    for(g=q.length()-1,nt=0;g>=0;g--){

        if(q[g]=='L')nt++;

        else if(nt)re[g+1]+=(nt+1)/2,re[g]+=nt/2,nt=0;

    }

    for(g=0;g<q.length()-1;g++)

        printf("%d ",re[g]);

    printf("%d\n",re[g]);

    return 0;

}