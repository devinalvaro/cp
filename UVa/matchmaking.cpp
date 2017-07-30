/* greedy : involving sorting */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int b, s, age, t = 0;
    vector<int> bach, spin;
    cin >> b >> s;

    while (b != 0 || s != 0) {
        t++;
        bach.clear();
        spin.clear();

        for (int i = 0; i < b; ++i) {
            cin >> age;
            bach.push_back(age);
        }

        for (int i = 0; i < s; ++i) {
            cin >> age;
            spin.push_back(age);
        }

        sort(bach.begin(), bach.end());
        sort(spin.begin(), spin.end());

        if (b > s) {
            cout << "Case " << t << ": " << b - s << ' ' << bach[0] << '\n';
        } else {
            cout << "Case " << t << ": 0\n";
        }

        cin >> b >> s;
    }
}
