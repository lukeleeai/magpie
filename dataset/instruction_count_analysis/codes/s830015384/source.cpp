#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <queue>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <climits>

#include <cstdlib>

#include <ctime>

#include <cstring>

#include <cassert>

#include <unordered_set>

#include <unordered_map>

using namespace std;

int a, b;

int main() {

    while (cin >> a >> b) {

        a *= b;

        if (a % 2 == 1) cout << "Odd" << endl;

        else cout << "Even" << endl;

    }

    return 0;

}
