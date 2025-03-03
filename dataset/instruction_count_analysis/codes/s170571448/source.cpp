#include <iostream>

#include <cstdlib>

#include <iomanip>

#include <cmath>

#include <string>

#include <cstring>

#include <algorithm>

#include <vector>

#include <sstream>

#include <set>

#include <queue>

#include <stack>

#include <cctype>

#include <map>

#include <climits>

#include <bitset>

using namespace std;

#define MATH_PI 3.14159265358979323846

struct Knife{

	int iHurt;

	int iType=0;

}arrKnives[1000000];



bool cmp(Knife nifKnife1, Knife nifKnife2){

	return (nifKnife1.iHurt>nifKnife2.iHurt);

}



int main(){

	ios::sync_with_stdio(false);

	int n, iHP;

	register int i,c = 0;

	scanf("%d %d", &n, &iHP);

	for (i = 1; i <= n; ++i){

		scanf("%d", &arrKnives[c].iHurt);

		++c;

		arrKnives[c].iType = 1;

		scanf("%d", &arrKnives[c].iHurt);

		++c;

	}

	sort(arrKnives, arrKnives + c, cmp);

	int iSum = 0;

	for (i = 0; i<c; ++i){

		if (arrKnives[i].iType == 1){

			++iSum;

			iHP -= arrKnives[i].iHurt;

			if (iHP <= 0){

				printf("%d", iSum);

				break;

			}

		}

		else if (arrKnives[i].iType != 1){

			if (iHP%arrKnives[i].iHurt == 0)

				iSum += iHP / arrKnives[i].iHurt;

			else 

				iSum += iHP / arrKnives[i].iHurt + 1;

			printf("%d", iSum);

			break;

		}

	}

endapp:

	//system("pause > nul");

	return 0;

}