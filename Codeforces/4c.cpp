#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    string s;
    map<string, int> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (m.find(s) == m.end()) {
            m[s] = 1;
            cout << "OK" << endl;
        } else {
            cout << s << m[s]++ << endl;
        }
    }
}
