/* 

 * I used # 1687007 as a refference. Thx. 

 */

#include <iostream>

#include <queue>

#include <set>

#include <cassert>

#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cctype>



using namespace std;



typedef long long Board;



const int N = 9;

//const int PATTERN = 181440;     // 9! / 2;

const int PATTERN = 362880;     // 9! / 2;

const int FORWARD  = 1;

const int BACKWARD = -1;

const Board GOAL = 0x123456780LL;

const int DX[] = { -1, 0, 1,  0 },

          DY[] = {  0, 1, 0, -1 };



int history[PATTERN];

queue<Board> q;



// I made this function based on one by Haruhiko Okumura(Algorithm 

// Dictionary, p116) and one by M.Hiroi(Puzzle DE Programming).

inline int change_number(long long board) {

    static int fact_table[N] = {

         40320, 5040, 720, 120, 24, 6, 2, 1, 0      // on N = 8

    };

    int value = 0;

    for (int j = 0; j < N - 1; ++j) {

        int J = static_cast<int>((board >> (j*4) & 0xF));

        value += fact_table[j] * J;

        for (int k = j + 1; k < N; ++k) {

            int K = static_cast<int>((board >> k*4) & 0xF);

            if (J < K) {

                board &= ~(0xFLL << k*4);

                board |= (static_cast<long long>(K - 1) << k*4);

            }

        }

    }

//    printf("[change_number] value = %d\n", value);

    return value;

}



inline void swap(int numpos, int spacepos, Board& board) {

    long long num = (board >> (numpos*4)) & 0xF;

    board |= num << (spacepos*4);

    board &= ~(0xFLL << (numpos*4));

}



inline int swap_and_check(int numpos, int spacepos, Board board) {

//    printf("change_number(board) = %d\n", change_number(board));

    int direction = history[change_number(board)];

    swap(numpos, spacepos, board);

    int pos = change_number(board);

    if (history[pos] == 0) {

        q.push(board);

        history[pos] = direction + (direction > 0 ? 1 : -1);

    }

    else if ((history[pos] > 0 && direction < 0)

          || (history[pos] < 0 && direction > 0)) {

        return abs(history[pos]) + abs(direction) - 1;

    }

    return 0;

}



void print(Board b) {

    for (int i = N - 1; i >= 0; --i) {

        printf("%2lld", (b >> (i*4) & 0xF));

    }

    printf("\n");

}



// OK

int main(void) {



    Board board = 0;

    for (int i = N - 1, num; i >= 0; --i) {

        scanf("%d", &num);

        board |= static_cast<long long>(num) << (i * 4);

    }

//    print(board);

//    print(GOAL);



    int count = 0;

    if (board == GOAL) {

        goto END;

    }



    history[change_number(board)] = FORWARD;

    history[change_number(GOAL)]  = BACKWARD;



    q.push(board);

    q.push(GOAL);

    while (!q.empty()) {

        board = q.front();

        q.pop();



        int pos = -1;

        while (++pos < N)

            if (((board >> (pos * 4)) & 0xF) == 0)

                break;



        int zx = pos % 3, zy = pos / 3;

        for (int i = 0; i < 4; ++i) {

            int nx = zx + DX[i], ny = zy + DY[i];

            if (nx < 0 || nx > 2 || ny < 0 || ny > 2)

                continue;

            int npos = nx + ny * 3;

//            printf("npos = %d\n", npos);

            assert(pos >= 0 && pos < N);

            assert(npos >= 0 && npos < N);

            if ((count = swap_and_check(npos, pos, board)))

                goto END;

        }

//        printf("\n");

    }



END:

    printf("%d\n", count);



    return 0;

}