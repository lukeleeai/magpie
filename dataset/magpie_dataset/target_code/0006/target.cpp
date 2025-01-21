# include <stdio.h>

	# include <string.h>

	int main () {

		int a = 0;

		int c =0;

	char name [100];

		scanf ("%d",&a);

		scanf("%s%[^\n]",&name);

		c = strlen (name);

		if (c<=a) {

			printf ("%s",name);

		} else if (c>a) {

			for (int i = 0;i<a;i++) {

				printf ("%c",name[i]);

			}

			printf("...");

		}

		return 0;

	}