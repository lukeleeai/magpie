/*

 */

#include <iostream>

#include <algorithm>



using namespace std;



// init

// fe[u

int prime[9692]; // 9,592(100,000 ÈºÌfÌ) + 100(iP ÌÅål)

int primeN;



// input

int iN; // 0 <= N <= 100,000

int iP; // 1 <= P <= 100



// manage

int iM[5050]; // 1 ~ 100 ÜÅÌa



// ú»

void init() {

  int i, j;

  bool isPrime[101198]; // 9692 ÔÚÌf = 101197



  primeN = 0;

  fill(isPrime, isPrime + 101198, true);

  isPrime[0] = isPrime[1] = false;



  for (i = 2; i < 101198; i++) {

    if (isPrime[i]) {

      prime[primeN++] = i;

      for (j = 2; i * j < 101198; j++) {

        isPrime[i * j] = false;

      }

    }

  }

}



// üÍ

bool input() {

  scanf("%d %d", &iN, &iP);

  if (iN == -1 && iP == -1) return false;

  return true;

}



// 

void manage(){

  int i, j, k;

  int cnt = 0;

  int tmp;



  // iN æèå«¢f©ç 2 ÂðIñÅaðÆé

  for (i = 0; i < primeN; i++) {

    if (prime[i] > iN) break;

  }

  for (j = 0; j < iP; j++) {

    for (k = j; k < iP; k++) {

      iM[cnt++] = prime[i + j] + prime[i + k];

    }

  }



  // ou\[g(æª©çiPÔÜÅ\[g)

  for (j = 0; j < iP; j++) {

    for (k = cnt - 1; k > j; k--) {

      if (iM[k - 1] > iM[k]) {

        tmp = iM[k];

        iM[k] = iM[k - 1];

        iM[k - 1] = tmp;

      }

    }

  }

}



// oÍ

void output(){

  printf("%d\n", iM[iP - 1]);

}



// mizoSâ¤Ê

int main() {

  init(); // ú»

  while(1) {

    if (!input()) break; // üÍ + I¹»è

    manage(); // 

    output(); // oÍ

  }

  return 0;

}