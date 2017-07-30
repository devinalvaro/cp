#include <iostream>

using namespace std;

int main()
{
    long long a, b, s;
    cin >> a >> b >> s;

    if (s < abs(a) + abs(b)) {
        cout << "No";
    } else {
        if ((s - (abs(a) + abs(b))) & 1) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    }
    cout << endl;
}
