#include "stdc++.h"

using namespace std;



main()

{

int A,B,C,D, a[1000],b[1000],c[1000],n,aaa,k,i,r=0,rr=0,d1,dd=0,d2,d3,ck=0,m,j,aa,bb,cc;

//char cr[1000];

//scanf("%lld",&n);

//cin>>A>>B>>C>>D;

cin>>n;



for(i=1;i<=n;i++){



        for(j=1;j<=n;j++){



            for(k=1;k<=n;k++){

                aa=i;

                bb=j;

                cc=k;





        int x,y,z;

   // cout<<a[i]<<b[i]<<c[i]<<endl;









    if((aa<bb)&&(aa<cc)){

        x=aa;

    }

    else if((bb<aa)&&(bb<cc)){

        x=bb;

    }

    else{

        x=cc;

    }

  vvv:  if((aa%x==0)&&(bb%x==0)&&(cc%x==0)){

            y=x;



        dd=dd+y;

        x=123456;

    }



   if(x!=123456){

    x=x-1;

   }

    if(x!=123456)goto vvv;







}



}}



  cout<<dd;

//printf("%lld",dd);



    return 0;

}