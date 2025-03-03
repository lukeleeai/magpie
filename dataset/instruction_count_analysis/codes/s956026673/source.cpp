#include<iostream>

#include<string>

#include<algorithm>

#include<cstdlib>

template<typename T>

void fin(T const& t){ std::cout << t << std::endl; exit(0); }



int const MAXL = 2000;



bool ngAC[MAXL*5], ngBC[MAXL*5];



int main() {

  std::string a, b, c; std::cin >> a >> b >> c;

  int aL = a.size(), bL = b.size(), cL = c.size();

  int mL = std::max(aL, std::max(bL, cL));

  std::fill_n(ngAC, MAXL*5, false);

  std::fill_n(ngBC, MAXL*5, false);

  for(int i = 0; i < aL; ++i) for(int j = 0; j < cL; ++j) {

    if(a[i]!='?' && c[j]!='?' && a[i]!=c[j]) ngAC[MAXL*2+i-j] = true;

  }

  for(int i = 0; i < bL; ++i) for(int j = 0; j < cL; ++j) {

    if(b[i]!='?' && c[j]!='?' && b[i]!=c[j]) ngBC[MAXL*2+i-j] = true;

  }

  

  int ans = aL+bL+cL;

  for(int ob = -bL-cL; ob < aL+cL; ++ob) {

    int bl = std::min(0, ob), br = std::max(aL, ob+bL);

    if(br - bl > ans) continue;

    // check AB match

    bool ok = true;

    for(int x = std::max(0, ob); x < std::min(aL, ob+bL); ++x) {

      if(a[x]!='?' && b[x-ob]!='?' && a[x]!=b[x-ob]) { ok = false; break; }

    }

    if(!ok) continue;

    for(int oc = -bL-cL; oc < aL+bL; ++oc) {

      int cl = std::min(bl, oc), cr = std::max(br, oc+cL);

      if(cr - cl > ans) continue;

      if(ngAC[MAXL*2+oc]) continue;

      if(ngBC[MAXL*2+oc-ob]) continue;

      ans = cr - cl;

    }

  }

  fin(ans);

  return 0;

}
