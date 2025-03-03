//          .,:,,,                                        .::,,,::.

//        .::::,,;;,                                  .,;;:,,....:i:

//        :i,.::::,;i:.      ....,,:::::::::,....   .;i:,.  ......;i.

//        :;..:::;::::i;,,:::;:,,,,,,,,,,..,.,,:::iri:. .,:irsr:,.;i.

//        ;;..,::::;;;;ri,,,.                    ..,,:;s1s1ssrr;,.;r,

//        :;. ,::;ii;:,     . ...................     .;iirri;;;,,;i,

//        ,i. .;ri:.   ... ............................  .,,:;:,,,;i:

//        :s,.;r:... ....................................... .::;::s;

//        ,1r::. .............,,,.,,:,,........................,;iir;

//        ,s;...........     ..::.,;:,,.          ...............,;1s

//       :i,..,.              .,:,,::,.          .......... .......;1,

//      ir,....:rrssr;:,       ,,.,::.     .r5S9989398G95hr;. ....,.:s,

//     ;r,..,s9855513XHAG3i   .,,,,,,,.  ,S931,.,,.;s;s&BHHA8s.,..,..:r:

//    :r;..rGGh,  :SAG;;G@BS:.,,,,,,,,,.r83:      hHH1sXMBHHHM3..,,,,.ir.

//   ,si,.1GS,   sBMAAX&MBMB5,,,,,,:,,.:&8       3@HXHBMBHBBH#X,.,,,,,,rr

//   ;1:,,SH:   .A@&&B#&8H#BS,,,,,,,,,.,5XS,     3@MHABM&59M#As..,,,,:,is_

//  .rr,,,;9&1   hBHHBB&8AMGr,,,,,,,,,,,:h&&9s;   r9&BMHBHMB9:  . .,,,,;ri.

//  :1:....:5&XSi;r8BMBHHA9r:,......,,,,:ii19GG88899XHHH&GSr.      ...,:rs.

//  ;s.     .:sS8G8GG889hi.        ....,,:;:,.:irssrriii:,.        ...,,i1,

//  ;1,         ..,....,,isssi;,        .,,.                      ....,.i1,

//  ;h:               i9HHBMBBHAX9:         .                     ...,,,rs,

//  ,1i..            :A#MBBBBMHB##s                             ....,,,;si.

//  .r1,..        ,..;3BMBBBHBB#Bh.     ..                    ....,,,,,i1;

//   :h;..       .,..;,1XBMMMMBXs,.,, .. :: ,.               ....,,,,,,ss.

//    ih: ..    .;;;, ;;:s58A3i,..    ,. ,.:,,.             ...,,,,,:,s1,

//    .s1,....   .,;sh,  ,iSAXs;.    ,.  ,,.i85            ...,,,,,,:i1;

//     .rh: ...     rXG9XBBM#M#MHAX3hss13&&HHXr         .....,,,,,,,ih;

//      .s5: .....    i598X&&A&AAAAAA&XG851r:       ........,,,,:,,sh;

//      . ihr, ...  .         ..                    ........,,,,,;11:.

//         ,s1i. ...  ..,,,..,,,.,,.,,.,..       ........,,.,,.;s5i.

//          .:s1r,......................       ..............;shs,

//          . .:shr:.  ....                 ..............,ishs.

//              .,issr;,... ...........................,is1s;.

//                 .,is1si;:,....................,:;ir1sr;,

//                    ..:isssssrrii;::::::;;iirsssssr;:..

//                         .,::iiirsssssssssrri;;:.

/*

author:uin

date:2020.2.10

*/

#include <iostream>

#include <algorithm>

#include <cmath>

#include <cstdlib>

#include <cstdio>

#include <cstring>

#include <iomanip>

#include <string>

#include <set>

#include <vector>

#include <queue>

#include <stack>

#include <map>

#define ll long long

#define ull unsigned ll

#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl '\n'

#define ff1(i, n) for (int i = 1; i <= n; ++i)

#define ff0(i, n) for (int i = 0; i < n; ++i)

#define pi acos(-1.0)

#define ms(T, x) memset(T, x, sizeof(T))

#define lowbit(x) ((x) & (-(x)))

#define pb push_back

#define binarycount __builtin_popcount(x)

#define tr t[root]

#define lson t[root << 1]

#define rson t[root << 1 | 1]

#define ans first

#define sec second

#define debug(x) cout << x << '\n'

#define sa(T) scanf("%d", &T)

#define sab(T, b) scanf("%d%d", &T, &b)

#define pa(T) printf("%d", T)

#define pab(T, b) printf("%d%d", T, b)

#define pii pair<ll, pair<ll, ll>>

using namespace std;



const int maxn = 100005;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const int mod = 9973;

const ll inf = ((1LL << 62) - 1) | (1LL << 62);

const int maxx = 1e3 + 10;

const double eps = 1e-8;

ll gcd(ll T, ll b) { return b == 0 ? T : gcd(b, T % b); }

ll lcm(ll T, ll b) { return T / gcd(T, b) * b; }

int max(int x, int y)

{

    if (x > y)

        return x;

    return y;

}

ll powmod(ll T, ll b)

{

    ull v = 1, pow = T % mod;

    while (b)

    {

        if (b & 1)

            v = (v * pow) % mod;

        pow = (pow * pow) % mod;

        b >>= 1;

    }

    return v % mod;

}



bool is_prime(int x)

{

    if (x < 2)

        return false;

    int len = sqrt(x);

    for (int i = 2; i <= len; i++)

    {

        if (x % i == 0)

            return false;

    }

    return true;

}



int main(){

	IO;

	ll x;

    cin>>x;

	for(ll i=0;i<=200;i++){

		for(ll j=-i;j<=i;j++){

            ll a=i*i*i*i*i;

            ll b=j*j*j*j*j;

			if(a-b==x) {

                cout<<i<<" "<<j<<'\n';

                return 0;

            }

		}

	}

	return 0;

}
