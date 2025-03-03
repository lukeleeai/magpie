#include <iostream>

#include <string>

#include <utility>

#include <vector>



using namespace std;



void max_heapify(vector<int>& H, int i, int size)

{

    int left = i * 2;

    int right = i * 2 + 1;



    int max = i;

    if (left <= size && H[max] < H[left])

        max = left;

    if (right <= size && H[max] < H[right])

        max = right;



    if (max != i) {

        swap(H[max], H[i]);

        max_heapify(H, max, size);

    }

}



void build_max_heap(vector<int>& H, int size)

{

    for (int i = size / 2; i > 0; --i)

        max_heapify(H, i, size);

}



void insert(vector<int>& S, int key, int& last)

{

    ++last;

    S[last] = key;



    int child = last;

    int parent = child / 2;

    while (parent > 0 && child > 0 && S[parent] < S[child]) {

        swap(S[parent], S[child]);

        child = parent;

        parent = child / 2;

    }

}



int extract_max(vector<int>& S, int& last)

{

    if (last < 1)   // priority queue is empty

        return -1;



    int max = S[1]; // first elem is max value



    S[1] = S[last];

    --last;

    max_heapify(S, 1, last);



    return max;

}



int main()

{

    const int max_instruction = 2000000;

    vector<int> S(max_instruction + 1);

    int last = 0;



    while (true) {

        string instruction;

        cin >> instruction;



        if (instruction == "end") {

            break;

        } else if (instruction == "extract") {

            int max = extract_max(S, last);

            cout << max << '\n';

        } else {

            int k;

            cin >> k;

            insert(S, k, last);

        }

    }

}


