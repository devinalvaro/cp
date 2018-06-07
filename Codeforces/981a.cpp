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

bool isPalindrome(string &s) {
    string r = s;
    reverse(r.begin(), r.end());

    return s == r;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string t = s.substr(i, j - i + 1);
            if (!isPalindrome(t)) {
                r = max(r, (int)t.size());
            }
        }
    }

    cout << r << endl;

    return 0;
}
