#include <cstdio>

#include <cstring>

#include <vector>

using namespace std;



char s[200002];

vector<int> p[27];

int r[200002], tr[200002];



int main(){

  scanf("%s", s + 1); int L = strlen(s + 1);

  for(int i = 1; i <= L; i++) p[s[i] & 31].push_back(i);



  int o = 0;

  for(int i = 1; i <= 26; i++){

    int z = p[i].size();

    if(z & 1){ o++; r[p[i][z / 2]] = (L + 1) / 2; }

  }



  if(o > 1){ puts("-1"); return 0; }



  for(int i = 1, z = 1; i <= L; i++){

    if(r[i] == 0){

      r[i] = z; r[p[s[i] & 31].back()] = L + 1 - z;

      z++; p[s[i] & 31].pop_back();

    }

  }



  long long ans = 0;



  for(int i = L; i >= 1; i--){

    for(int x = r[i]; x > 0; x -= x & -x) ans += tr[x];

    for(int x = r[i]; x <= L; x += x & -x) tr[x]++;

  }



  printf("%lld\n", ans);

  return 0;

}