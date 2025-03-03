#include <iostream>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>



using namespace std;



int N;

int A, B, mini=99999999;

char a[10];

char b[10];

int sumA, sumB;



int main()

{

  cin >> N;

  if(N % 2 == 0)

  {

    A = N / 2;

    B = N / 2;

  }

  else

  {

    A = N / 2;

    B = (N / 2) + 1;

  }

  while(A>0)

  {

    sprintf(a, "%d", A);

    sprintf(b, "%d", B);

    for(int i=0; i<strlen(a); i++)

      sumA += a[i] - 48;

    for(int i=0; i<strlen(b); i++)

      sumB += b[i] - 48;

    if(sumA + sumB < mini)

      mini = sumA + sumB;

    sumA = 0;

    sumB = 0;

    A--;

    B++;

  }

  cout << mini << "\n";

  return 0;

}
