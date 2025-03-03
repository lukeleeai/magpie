#include "stdio.h"

#include <math.h>

int main()

{

	int n,R,Min;

	int diff = (int)pow(10, 9)*-1-1;



	scanf("%d %d",&n,&Min);

	for (int i = 0; i < n-1; i++) {

		scanf("%d", &R);

		if (diff < R - Min) {

			diff = R - Min;

		}

		if (Min > R) {

			Min = R;

		}

	}

	printf("%d\n", diff);

    return 0;

}
