#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <stack>

using namespace std;

int n = {}, k = {};
array<string, 11> integer = {};
vector<string> num = {};
array<int, 11> chousen = {};
set<string> complete_integer;
string answer;
int integer_count = 0;

void operation() {
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int i = s.top();
        s.pop();

        if (i > n) {
            continue;
        }

        if (chousen[i] == 0) {
            chousen[i] = 1;
            num.push_back(integer[i]);

            if (num.size() == k) {
                answer.clear();
                answer.reserve(k * 100);
                
                for (int j = 1; j <= k; j++) {
                    answer += num[j - 1];
                }

                if (complete_integer.insert(answer).second) {
                    integer_count++;
                }
            } else {
                s.push(i + 1);
                s.push(1); // Restart the loop with the first index
            }

            num.pop_back();
            chousen[i] = 0;
        }

        s.push(i + 1);
    }
}

int main() {
    while (true) {
        cin >> n >> k;

        if (n == 0 && k == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            cin >> integer[i];
        }

        operation();

        cout << integer_count << endl;

        n = {};
        k = {};
        integer.fill("");
        chousen.fill(0);
        num.clear();
        complete_integer.clear();
        answer.clear();
        integer_count = 0;
    }
    return 0;
}
