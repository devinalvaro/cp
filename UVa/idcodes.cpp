/* ds : C++ STL */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    while (s != "#") {
        string s0 = s;
        sort(s0.begin(), s0.end());
        next_permutation(s.begin(), s.end());

        if (s != s0) {
            cout << s << '\n';
        } else {
            cout << "No Successor\n";
        }

        cin >> s;
    }
}
