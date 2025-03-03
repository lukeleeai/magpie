#include<cstdio>

#include<algorithm>

using namespace std;



bool arr[1005];

int hash_[1005];

const int MOD = 1e9+7;

void init(){

arr[1] = 1;

arr[2] = 1;

arr[3] = 1;

arr[5] = 1;

arr[7] = 1;

arr[11] = 1;

arr[13] = 1;

arr[17] = 1;

arr[19] = 1;

arr[23] = 1;

arr[29] = 1;

arr[31] = 1;

arr[37] = 1;

arr[41] = 1;

arr[43] = 1;

arr[47] = 1;

arr[53] = 1;

arr[59] = 1;

arr[61] = 1;

arr[67] = 1;

arr[71] = 1;

arr[73] = 1;

arr[79] = 1;

arr[83] = 1;

arr[89] = 1;

arr[97] = 1;

arr[101] = 1;

arr[103] = 1;

arr[107] = 1;

arr[109] = 1;

arr[113] = 1;

arr[127] = 1;

arr[131] = 1;

arr[137] = 1;

arr[139] = 1;

arr[149] = 1;

arr[151] = 1;

arr[157] = 1;

arr[163] = 1;

arr[167] = 1;

arr[173] = 1;

arr[179] = 1;

arr[181] = 1;

arr[191] = 1;

arr[193] = 1;

arr[197] = 1;

arr[199] = 1;

arr[211] = 1;

arr[223] = 1;

arr[227] = 1;

arr[229] = 1;

arr[233] = 1;

arr[239] = 1;

arr[241] = 1;

arr[251] = 1;

arr[257] = 1;

arr[263] = 1;

arr[269] = 1;

arr[271] = 1;

arr[277] = 1;

arr[281] = 1;

arr[283] = 1;

arr[293] = 1;

arr[307] = 1;

arr[311] = 1;

arr[313] = 1;

arr[317] = 1;

arr[331] = 1;

arr[337] = 1;

arr[347] = 1;

arr[349] = 1;

arr[353] = 1;

arr[359] = 1;

arr[367] = 1;

arr[373] = 1;

arr[379] = 1;

arr[383] = 1;

arr[389] = 1;

arr[397] = 1;

arr[401] = 1;

arr[409] = 1;

arr[419] = 1;

arr[421] = 1;

arr[431] = 1;

arr[433] = 1;

arr[439] = 1;

arr[443] = 1;

arr[449] = 1;

arr[457] = 1;

arr[461] = 1;

arr[463] = 1;

arr[467] = 1;

arr[479] = 1;

arr[487] = 1;

arr[491] = 1;

arr[499] = 1;

arr[503] = 1;

arr[509] = 1;

arr[521] = 1;

arr[523] = 1;

arr[541] = 1;

arr[547] = 1;

arr[557] = 1;

arr[563] = 1;

arr[569] = 1;

arr[571] = 1;

arr[577] = 1;

arr[587] = 1;

arr[593] = 1;

arr[599] = 1;

arr[601] = 1;

arr[607] = 1;

arr[613] = 1;

arr[617] = 1;

arr[619] = 1;

arr[631] = 1;

arr[641] = 1;

arr[643] = 1;

arr[647] = 1;

arr[653] = 1;

arr[659] = 1;

arr[661] = 1;

arr[673] = 1;

arr[677] = 1;

arr[683] = 1;

arr[691] = 1;

arr[701] = 1;

arr[709] = 1;

arr[719] = 1;

arr[727] = 1;

arr[733] = 1;

arr[739] = 1;

arr[743] = 1;

arr[751] = 1;

arr[757] = 1;

arr[761] = 1;

arr[769] = 1;

arr[773] = 1;

arr[787] = 1;

arr[797] = 1;

arr[809] = 1;

arr[811] = 1;

arr[821] = 1;

arr[823] = 1;

arr[827] = 1;

arr[829] = 1;

arr[839] = 1;

arr[853] = 1;

arr[857] = 1;

arr[859] = 1;

arr[863] = 1;

arr[877] = 1;

arr[881] = 1;

arr[883] = 1;

arr[887] = 1;

arr[907] = 1;

arr[911] = 1;

arr[919] = 1;

arr[929] = 1;

arr[937] = 1;

arr[941] = 1;

arr[947] = 1;

arr[953] = 1;

arr[967] = 1;

arr[971] = 1;

arr[977] = 1;

arr[983] = 1;

arr[991] = 1;

arr[997] = 1;

}



int main(){

    int n;

    scanf("%d",&n);

    init();

    long long ans = 1;// n = 1

    for(int i=2;i<=n;i++){

        if(arr[i])hash_[i]++;// 素数

        else for(int j=2,t=i;j<=t;j++){

            while(t%j==0){

                hash_[j]++;

                t/=j;

            }

        }

    }

    for(int i=1;i<=n;i++){

        if(hash_[i])

            ans = ans*(hash_[i]+1)%MOD;

    }



    printf("%d",ans);

    return 0;

}
