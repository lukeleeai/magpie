# include<stdio.h>



# include<malloc.h>



void sort(int *, int len);



int main(void)

{

	int len;

	int * pArr;

	int i, j = 0;

	//int a[100000] = {0};

	int sum1 = 0;

	int sum2 = 0;

	//int *p = (int *)malloc(int len)

		//malloc() the return is"void *"也叫干地址

	scanf("%d", &len);

	pArr = (int *)malloc(sizeof(int)*len);;

	for(i=0; i<len; ++i)

	{

		scanf("%d", &pArr[i]);

	}

	

	for(i=0; i<len-1; ++i)

	{

		if(pArr[i]>=pArr[i+1])

		{

			sum1 += 1;

			//a[j] += 1;

		}

		if(pArr[i]<pArr[i+1])

		{

			if(sum1>sum2)

			{

				sum2 = sum1;

			}

			

			sum1 = 0;

			

				//j++;

		}

	}



	if(sum1>sum2)

			{

				sum2 = sum1;

			}



	printf("%d", sum2);

	//sort(a, j+1);



	return 0;

}
