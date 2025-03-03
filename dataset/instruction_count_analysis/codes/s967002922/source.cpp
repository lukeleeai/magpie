#include <stdio.h>



int main (){

	

	int h, w, n;

	scanf("%d %d %d", &h, &w, &n);

	

	int tot;

	

	if(h>=w) {

        if(n%h == 0) {

            tot = n/h;

        } else {

            tot = n/h+1;

        }

    } else {

        if(n%w == 0) {

            tot = n/w;

        } else {

            tot = n/w+1;

        }

    }

	printf("%d", tot);

	

	return 0;

}