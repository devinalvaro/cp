#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string n;
    cin >> n;

    for (int i = 0; i < (int)n.size(); i++) {
        for (int j = i; j < (int)n.size(); j++) {
            for (int k = j; k < (int)n.size(); k++) {
                int num = n[i] - '0';

                if (j != i) {
                    num *= 10;
                    num += n[j] - '0';
                }

                if (k != j) {
                    num *= 10;
                    num += n[k] - '0';
                }

                if (num % 8 == 0) {
                    cout << "YES" << endl;
                    cout << num << endl;

                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
