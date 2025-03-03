#include "stdc++.h"

using namespace std;

 

int N;

long long A[101], B[101];

int op[101], bb, cc, dd;

bool vis[101];

 

long long bf(int n) {

  if(n == bb) {

    long long ans = 0;

    for(int i = bb; i < cc; i++) {

      if(op[i] == 0) {

//        vis[i] = 1, vis[i + i] = 1;

        ans += max(0LL, A[i] + (op[i + i] == 0 ? B[i + i] : 0));

      }

    }

    for(int i = cc; i < dd; i++) {

      if(op[i] == 0) {

//        vis[i] = 1;

        ans += B[i];

      }

    }

    for(int i = dd + 1; i <= N; i+=2) {

      if(op[i] == 0) {

//        vis[i] = 1;

        ans += B[i];

      }

    }

    return ans;

  }

  if(op[n]) {

    return bf(n + 1);

  }else {

    long long now = A[n] + bf(n + 1);

    for(int i = n + n; i <= N; i += n) {

      op[i]++;

    }

    now = max(now, bf(n + 1));

    for(int i = n + n; i <= N; i += n) {

      op[i]--;

    }

    return now;

  }

}

 

long long bf2(int n) {

  if(n + n > N) {

    long long ans = 0;

    for(int i = n; i <= N; i++) {

      if(op[i] == 0) ans += B[i];

    }

    return ans;

  }

  if(op[n]) {

    return bf2(n + 1);

  }else {

    long long now = A[n] + bf2(n + 1);

    for(int i = n + n; i <= N; i += n) {

      op[i]++;

    }

    now = max(now, bf2(n + 1));

    for(int i = n + n; i <= N; i += n) {

      op[i]--;

    }

    return now;

  }

}

 

 

int main() {

  scanf("%d", &N);

  bb = N / 3 + 1;

  cc = N / 2 + 1;

  dd = bb + bb;

  for(int i = 1; i <= N; i++) {

    scanf("%lld", &A[i]);

    if(A[i] > 0) B[i] = A[i];

  }

  if(N < 10) printf("%lld\n", max(0LL, A[1] + bf2(2)));

  else printf("%lld\n", max(0LL, A[1] + bf(2)));

//  for(int i = 1; i <= N; i++) if(!vis[i])cout << i << "\n";

  cin >> N;

}