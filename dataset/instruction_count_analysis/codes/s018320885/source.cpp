#include<stdio.h>  

int a[105][105];

int b[10050];  

   

int main()  

{  

    int H,W;  

    while(scanf("%d%d",&H,&W)!=EOF)  

    {  

        int t,k=0;  

        scanf("%d",&t);  

        for(int i=0;i<t;i++)  

        {

		scanf("%d",&b[i]);

	}

        for(int i=0;i<H;i++)  

        {  

            if(i%2==0)  

            {

	         for(int j=0;j<W;j++)  

            	 {  

                	a[i][j]=k+1;  

          	      	b[k]--;  

            	        if(b[k]==0) k++;  

            	 }

	     }

            else if(i%2==1)  

            {

	         for(int j=W-1;j>=0;j--)  

     	       	 {  

        	        a[i][j]=k+1;  

            	        b[k]--;  

                	if(b[k]==0) k++;  

                 }  

            }

        }  

        for(int i=0;i<H;i++)  

        {  

            for(int j=0;j<W-1;j++)  

            {

		    printf("%d ",a[i][j]);

            }

            printf("%d\n",a[i][W-1]);  

        }  

    }  

}