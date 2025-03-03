#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Disable sync with C-style I/O
    cin.tie(nullptr); // Untie cin from cout for faster I/O
    int n, a, b;
    bool flag;
    string number;
    unordered_map<string, int> info;
    vector<string> seq;

    while (cin >> n && n) {
        info.clear();
        seq.clear();
        while (n--) {
            cin >> number >> a >> b;
            if (!info[number]) seq.push_back(number);
            // Optimize the loop by directly adding the minimum of 'b' increments needed
            int limit = min(b, (1000000 - info[number]) / a);
            info[number] += limit * a;
            b -= limit; // Reduce the remaining b by the number of iterations performed
        }
        flag = true;
        for (const auto& s : seq) {
            if (info[s] >= 1000000) {
                flag = false;
                cout << s << endl;
            }
        }
        if (flag) cout << "NA" << endl;
    }
}
