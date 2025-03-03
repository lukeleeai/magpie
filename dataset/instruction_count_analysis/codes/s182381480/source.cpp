 #include<stdio.h>

 int main()

 {

          int a,b,c,d,x,y;

          scanf("%d%d%d%d",&a,&b,&c,&d);

          x=(a+d-1)/d;

          y=(c+b-1)/b;

          if(x>=y)

                    printf("Yes\n");

          else

                    printf("No\n");

 return 0;

 }
