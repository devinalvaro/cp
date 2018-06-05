#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    int n;
    scanf("%d", &n);

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end(),
         [](string &a, string &b) { return a.size() < b.size(); });

    bool valid = true;
    for (int i = 1; i < n; i++) {
        if (s[i].find(s[i - 1]) == string::npos) {
            valid = false;
            break;
        }
    }

    if (valid) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            cout << s[i] << endl;
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
