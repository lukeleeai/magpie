#include <algorithm>

#include <iostream>

#include <list>

#include <string>

#include <map>

#include <utility>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cctype>



using namespace std;



typedef long long Board;



const int N = 9;

const Board GOAL = 0x087654321;



struct state {

    Board board;

    int count;

};



list<state> q;

map<Board,char> history;



inline void swap(int numpos, int spacepos, Board& board) {

    long long num = (board >> (numpos*4)) & 15;

    board |= num << (spacepos*4);

    board &= ~(15LL << (numpos*4));

}



inline int swap_and_check(int numpos, int spacepos, state s) {

    swap(numpos, spacepos, s.board);

    map<Board,char>::iterator it = history.find(s.board);

    if (it != history.end()) {

        return -1;

    }

    history.insert(make_pair(s.board, ' '));

    ++s.count;

    if (s.board == GOAL) {

        return s.count;

    }

    q.push_back(s);

    return -1;

}



void print(Board b) {

    for (int i = 0; i < N; ++i) {

        printf("%2lld", (b >> (i*4) & 15));

    }

    printf("\n");

}



int main(void) {



    Board board = 0;

    for (int i = 0; i < N; ) {

        char ch;

        scanf("%c", &ch);

        if (isdigit(ch)) {

            board |= static_cast<long long>((ch - '0')) << (i*4);

            ++i;

        }

    }



    if (board == GOAL) {

        printf("0\n");

        return 0;

    }



//    print(GOAL);

//    print(board);



    q.push_back({ board, 0 });

    int count = 0;

    while (!q.empty()) {

        state s = q.front();

        q.pop_front();

        // ?????????????????????

        int pos = -1;

        while (++pos < N) {

            if (((s.board >> (pos*4)) & 15) == 0) {

                break;

            }

        }

//        for (pos = 0; pos < N; ++pos) {

//            if (((s.board >> (pos*4)) & 15) == 0) {

//                break;

//            }

//        }



        if (pos < 6) {

            if ((count = swap_and_check(pos + 3, pos, s)) > 0) {

                break;

            }

        }

        if (pos > 2) {

            if ((count = swap_and_check(pos - 3, pos, s)) > 0) {

                break;

            }

        }

        if (pos % 3 < 2) {

            if ((count = swap_and_check(pos + 1, pos, s)) > 0) {

                break;

            }

        }

        if (pos % 3 > 0) {

            if ((count = swap_and_check(pos - 1, pos, s)) > 0) {

                break;

            }

        }

    }



    printf("%d\n", count);



    return 0;

}