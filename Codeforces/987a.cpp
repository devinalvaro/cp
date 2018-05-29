#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int n;
    scanf("%d", &n);

    map<string, string> thanos;
    thanos["blue"] = "Space";
    thanos["green"] = "Time";
    thanos["orange"] = "Soul";
    thanos["purple"] = "Power";
    thanos["red"] = "Reality";
    thanos["yellow"] = "Mind";

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        thanos.erase(s);
    }

    printf("%lu\n", thanos.size());
    for (auto it = thanos.begin(); it != thanos.end(); it++) {
        cout << it->second << '\n';
    }

    return 0;
}
