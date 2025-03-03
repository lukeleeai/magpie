#include <stdio.h>

 

int main()

{

    int n, ctr = 0;

    scanf("%d", &n);

    int input[n];

    for(int i = 0; i < n; i++)

    {

    	scanf("%d", &input[i]);

	}

	for (int i = 0; i < n-2; i++) 

	{

	    for (int j = i+1; j < n-1; j++) 

		{

	      for (int k = j+1; k < n; k++) 

		  {

			if ((input[i] == input[j]) || (input[j] == input[k]) || (input [k] == input[i])) 

			{

	          continue;

	        }

	        if (input[i] + input[j] > input[k] && input[j] + input[k] > input[i] && input[k]+ input[i] > input[j]) 

			{

	          ctr++;

	        }

      	  }

}

    }

  	printf("%d\n", ctr);

    return 0;

}