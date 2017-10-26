#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> friends = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

    string s;
    cin >> s;

    int friend_count = 0;
    for (int i = 0; i < (int)friends.size(); i++) {
        size_t j = s.find(friends[i]);
        while (j != string::npos) {
            friend_count++;

            j = s.find(friends[i], j + friends[i].size());
        }

        if (friend_count > 1) {
            cout << "NO\n";

            return 0;
        }
    }

    if (friend_count == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
