#include<stdio.h>



void ShellSort(int arr[],int n)

{

	int incre = 1;

	while(incre < n/3)

		incre = incre*3 + 1;

	for(;incre >= 1;incre/=3)

		for(int i = incre;i < n;i++)

		{

			int pos = i;

			int val = arr[i];

			for(;pos >= incre && val < arr[pos - incre];pos-=incre)

				arr[pos] = arr[pos - incre];

			arr[pos] = val;

		}

}



int Find(int arr[],int n)

{

    int ans = 0;

    for(int i = 0;i < n - 2;i++)

        for(int j = i + 1;j < n - 1;j++)

            for(int k = j + 1;k < n;k++)

            {

                if(arr[i] + arr[j] > arr[k]) ans++;

                else break;

            }

    return ans;

}  

int main()

{

    int n;

    scanf("%d",&n);

    int arr[10002];

    for(int i = 0;i < n;i++)

        scanf("%d",arr + i);

    ShellSort(arr,n);

    printf("%d\n",Find(arr,n));

    return 0;

}
