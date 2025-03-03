#include <iostream>

#include <string>

#include <queue>



using namespace std;



struct process {

    string name;

    int time;

};



int main(void) {

    int n, q;

    int time = 0;

    queue<process> p;



    cin >> n >> q;

    for (int i = 0; i < n; i++) {

        process temp;

        cin >> temp.name >> temp.time;

        p.push(temp);

    }

    while (not p.empty()) {

        process top = p.front();

        p.pop();

        if (top.time <= q) {

            time += top.time;

            cout << top.name << " " << time << endl;

        }

        else {

            time += q;

            top.time -= q;

            p.push(top);

        }

    }

    

    return 0;

}


