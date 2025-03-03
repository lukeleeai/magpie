#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;



char s[200002]; int cnt[28];

int gc[28];

char pre[100002], suf[100002];

int ptr[28], num[100002];

int tr[100002];



long long group(int L){

  long long res = 0;

  int oc = 0, tc = 0, pc = 0, sc = 0;



  for(int i = 1; i <= L; i++){

    int x = s[i] & 31, &g = gc[x], c = cnt[x]; g += 2;



    if(g < c + 1){ res += oc + tc; pre[++pc] = s[i]; }

    else if(g == c + 1){ res += tc; oc++; }

    else{ tc++; suf[++sc] = s[i]; }

  }



  return res;

}



int main(){

  scanf("%s", s + 1); int L = strlen(s + 1);

  for(int i = 1; i <= L; i++) cnt[s[i] & 31]++;



  int odd = 0;



  for(int i = 1; i <= 26; i++) if(cnt[i] & 1) odd++;



  if(odd > 1){ puts("-1"); return 0; }



  long long ans = group(L);



  int M = L / 2;



  reverse(suf + 1, suf + M + 1);



  for(int i = 1; i <= M; i++){

    char c = pre[i]; int &p = ptr[c & 31];

    while(suf[++p] != c);



    num[p] = i;

  }



  for(int i = M; i >= 1; i--){

    int x = num[i];

    for(int y = x - 1; y > 0; y -= y & -y) ans += tr[y];

    for(; x <= M; x += x & -x) tr[x]++;

  }



  printf("%lld\n", ans);

  return 0;

}