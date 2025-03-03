#include <stdio.h>





int main() 

{

    int a, b, c, x, t, sum = 0, bb;

    int imin, imax, y, z;

    

    scanf("%d%d%d%d", &a, &b, &c, &x);

    

    x /= 50, bb = b << 1;

    if(x & 1){

        if((c & 1) == 0) c--;	

    }

    else{

        if(c & 1) c--;

    }

        

    imin = 0;

    t = (x - bb - c) / 10;

    if(x - bb - c > 0 && (x - bb - c) % 10 != 0) t++;

    if(t > imin) imin = t;

    imax = a;

    t = x / 10;

    if(t < imax) imax = t;

    

    if(imax < imin){

    	puts("0");

    	return 0;

	}

	sum = imax - imin + 1;

	

	if(x < c) t = -1;

    else t = (x - c) / 10;

    if(t >= imin){

    	if(t > imax) t = imax;

    	y = (x - 10 * t - c) >> 1;

    	z = (x - 10 * imin - c) >> 1;

    	sum -= ((y + z) * (t - imin + 1)) >> 1;

	}

	

	if(x >= bb) t = (x - bb) / 10 + 1;

	else t = 0;

	if(t <= imax){

		if(t < imin) t = imin;

		y = (x - 10 * t) >> 1;

		z = (x - 10 * imax) >> 1;

		sum += ((y + z) * (imax - t + 1)) >> 1;

		sum += (t - imin) * b;

	}

	else sum += (imax - imin + 1) * b;

	printf("%d\n", sum);

	

    return 0;

}