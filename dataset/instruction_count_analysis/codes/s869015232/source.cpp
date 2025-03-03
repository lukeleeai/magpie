#include<stdio.h>

#include<string.h>

    char h[105][105];

    char q[105]={"0"};

    char w[10005];

int main()

{

	int i;

	int k;

	int p;

	int a;

	int b;

	       scanf("%d%d",&a,&b);

	   	  for(i=0;i<a;i++){

	   	  	   scanf("%s",h[i]);}

	      for(i=0;i<a-1;i++){

	      for(k=0;k<a-1-i;k++){

	      	  p=strcmp(h[k],h[k+1]);

				 if(p>0){

				 	strcpy(q,h[k]);

				 	strcpy(h[k],h[k+1]);

				 	strcpy(h[k+1],q);

				 }

	      	

		  }

	}

		  

		  

		  strcpy(w,h[0]);

		  for(i=1;i<a;i++)

		  	 strcat(w,h[i]);

			   printf("%s",w);

	return 0;	  

		  

}


