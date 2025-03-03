#include<stdio.h>

#include<algorithm>

#include<map>

using namespace std;

const int maxn = 1e5+1;

pair<int,int> s[maxn];

int n;

inline char readchar(){

    static const size_t bufsize = 1 << 16;

    static size_t p = 0, end = 0;

    static char buf[bufsize];

    if (p == end) end = fread_unlocked(buf, sizeof(char), bufsize, stdin), p = 0;

    return buf[p++];

}

template <typename T> inline void read(T& a){

    static char p;

    static bool b;

    while (!isdigit(p = readchar()))b = p == '-';

    a = p ^ '0';

    while (isdigit(p = readchar())) a *= 10, a += p ^ '0';

    if(b)a *= -1;

}

inline void read(char &a){

	static char p;

	while(isspace(p = readchar()));

	a = p;

}

inline void read(string &a){

	static char p;

	while(isspace(p = readchar()));

	a = p;

	while(!isspace(p = readchar()))a.push_back(p);

}



int main(){

    read(n);

    for(int i = 0;i < n;++i)read(s[i].first), read(s[i].second), ++s[i].second;

    sort(s, s+n);

    int l = 0, r = 1000000001, w = 0;

    for(int i = 0;i < n;++i){

        l = max(l, s[i].first);

        r = min(r, s[i].second);

        w = max(w, s[i].second-s[i].first);

    }

    int res = w+max(0, r-l);

    int su = s[n-1].second;

    for(int i = n-2;i > -1;--i)res = max(res, max(0, r-s[i].first) + max(0, su-l)), su = min(su, s[i].second);

    printf("%d\n", res);

}
