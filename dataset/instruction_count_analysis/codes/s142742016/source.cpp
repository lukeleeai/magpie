#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <cctype>

#include <ctime>

#include <set>

#include <algorithm>



namespace LegitStream

{

char bufdatum[BUFSIZ];

char *buf = bufdatum, *endbuf = bufdatum;



inline bool eof(void)

{

    if (endbuf == buf)

    {

        endbuf = (buf = bufdatum) + fread(bufdatum, 1, BUFSIZ, stdin);

        return endbuf == buf;

    }

    else

        return false;

}



inline int nextch(void)

{

    return eof() ? EOF : *buf++;

}



void legit(void) {}



template<typename Car, typename ...Cdr>

void legit(Car &var, Cdr &...Rest)

{

    int peek;

    while (!isdigit(peek = nextch())

#ifdef LEGIT_NEGI

        && peek != '-'

#endif  // LEGIT_NEGI

        )

        ;

#ifdef LEGIT_NEGI

    bool negi;

    if (peek == '-')

        negi = true;

    else

        negi = false;

#endif  // LEGIT_NEGI

    var = 0;

    do

        var = (((var << 2) + var) << 1) + (peek ^ '0');

    while (isdigit(peek = nextch()));

#ifdef LEGIT_NEGI

    if (negi)

        var = -var;

#endif  // LEGIT_NEGI

    legit(Rest...);

}

}

using LegitStream::nextch;

using LegitStream::eof;

using LegitStream::legit;



void solve(void);



int main(void)

{

#ifdef redirect

    freopen("check/data.in", "r", stdin);

    freopen("check/prog.out", "w", stdout);

    freopen("check/log.out", "w", stderr);

#endif  // redirect

#ifdef chrono

    auto begtm = clock();

#endif  // chrono

    solve();

#ifdef chrono

    auto endtm = clock();

    printf("%f\n", static_cast<float>(endtm - begtm) / CLOCKS_PER_SEC);

#endif  // chrono

    return 0;

}



enum class Direction

{

    Left,

    Right,

};



const size_t MaxN = size_t(3e5 + 7);



size_t n;

Direction queue[MaxN];

size_t tol[MaxN], tor[MaxN];



void solve(void)

{

    legit(n);

    for (int i = 0; i < n; ++i)

        queue[i] = nextch() == 'W' ? Direction::Left : Direction::Right;

    tor[0] = (queue[0] == Direction::Right);

    for (int i = 1; i < n; ++i)

        tor[i] = tor[i - 1] + (queue[i] == Direction::Right);

    tol[n - 1] = (queue[n - 1] == Direction::Left);

    for (int i = n - 2; i >= 0; --i)

        tol[i] = tol[i + 1] + (queue[i] == Direction::Left);



    size_t ans = 19260817;

    for (int i = 1; i < n - 1; ++i)

        ans = std::min(ans, n - 1 - tor[i - 1] - tol[i + 1]);

    ans = std::min(ans, n - 1 - tol[1]);

    ans = std::min(ans, n - 1 - tor[n - 2]);

    printf("%llu\n", ans);

}


