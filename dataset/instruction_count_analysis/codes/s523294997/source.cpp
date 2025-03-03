#include <iostream>

#include <queue>

#include <string>



using namespace std;



int main() {

    priority_queue<long> pq;

    string inst;

    while (true) {

        cin >> inst;

        if (inst == "end") {

            break;

        } else if (inst == "insert") {

            long key;

            cin >> key;

            pq.push(key);

        } else {

            cout << pq.top() << '\n';

            pq.pop();

        }

    }

}


