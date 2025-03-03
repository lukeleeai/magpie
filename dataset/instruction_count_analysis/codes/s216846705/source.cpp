#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<math.h>

#define pi acos(-1.0)

using namespace std;

int main() {

	int s = -1, e = -1;

	char str[100000+5];

	scanf("%s", str);

	int len = strlen(str);

	for(int i = 0; str[i]; i++) {

		if(str[i] == str[i + 1]) {

			s = i + 1;

			e = i + 2;

			break;

		} else if(str[i] == str[i + 2]) {

			s = i + 1;

			e = i + 3;

			break;

		}

	}

	printf("%d %d\n",s,e);	

	return 0;

}