#include<stdio.h>

#include<math.h>

signed main(void)

{

  int A,B,H,M;

  if(~scanf("%d %d %d %d",&A,&B,&H,&M))

  {

    double theta=(60*H-11*M)*M_PI/360.0,x=A-B*cos(theta),y=B*sin(theta);

    return printf("%.20f",sqrt(x*x+y*y)),0;

  }

}