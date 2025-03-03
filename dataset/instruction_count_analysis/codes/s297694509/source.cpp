#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <string.h>

#include <assert.h>



using namespace std;



#define MAXDATA			2000000

#define APPTXT_BUFSZ	128



#define countof(arr)		(sizeof(arr) / sizeof(arr[0]))



static int g_anDataBuf[MAXDATA];

static bool g_abInvalid[MAXDATA];



int main(void) {

	char str[APPTXT_BUFSZ];

	int bgn, end;

    int n;

    int x;



	fgets(str, APPTXT_BUFSZ, stdin);

	n = atoi(&(str[0]));



	bgn = end = countof(g_anDataBuf);

	while( n-- > 0 && fgets(str, APPTXT_BUFSZ, stdin) != NULL ) {

		if (str[0] == 'i') {		// ("insert"?¢????)

			x = atoi(&(str[sizeof("insert") - 1]));

			g_anDataBuf[--bgn] = x;

			g_abInvalid[bgn] = false;

        } else {

			int c = str[sizeof("delete") - 1];

			if (isalpha(c)) {

				if (c == 'F') {		// ("deleteFirst"?¢????)

					while (bgn < end && g_abInvalid[bgn++]) { }

					assert(bgn <= end);

				} else {			// ("deleteLast"?¢????)

					while (bgn < end && g_abInvalid[--end]);

					assert(bgn <= end);

				}

			} else {				// ("delete"?¢????)

				x = atoi(&(str[sizeof("delete") - 1]));

				for (int i = bgn; i < end; i++) {

					if (g_abInvalid[i]) {

						continue;

					}

					if (g_anDataBuf[i] == x) {

						g_abInvalid[i] = true;

						break;

					}

				}

			}

		}

    }



	//display list

	bool bFirst = true;

	for (int i = bgn; i < end; i++) {

		if (g_abInvalid[i]) {

			continue;

		}

		const int x = g_anDataBuf[i];

		if (bFirst) {

			printf("%d", x);

			bFirst = false;

		} else {

			printf(" %d", x);

		}

	}

	fputc('\n', stdout);



	return 0;

}