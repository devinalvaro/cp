#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ve vector
#define pq priority_queue
#define um unordered_map
#define us unordered_set

#define pii pair<int, int>
#define pll pair<ll, ll>

struct Journal {
    string title;
    string subtitle;
    string name;
    int vol;
    int issue;
    int year;
};

bool cmp(const Journal &a, const Journal &b) {
    if (a.name < b.name)
        return true;
    if (b.name < a.name)
        return false;

    if (a.year < b.year)
        return true;
    if (b.year < a.year)
        return false;

    if (a.vol < b.vol)
        return true;
    if (b.vol < a.vol)
        return false;

    if (a.issue < b.issue)
        return true;
    if (b.issue < a.issue)
        return false;

    if (a.title < b.title)
        return true;
    if (b.title < a.title)
        return false;

    if (a.subtitle < b.subtitle)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;

    ve<Journal> js;

    for (int i = 0; i < n; i++) {
        string title, subtitle, name;
        int vol, issue, year;

        cin >> ws;
        getline(cin, title);

        cin >> ws;
        getline(cin, subtitle);

        cin >> ws;
        getline(cin, name);

        cin >> vol >> issue >> year;

        Journal j = {title, subtitle, name, vol, issue, year};
        js.pb(j);

        // cout << js[i].title << endl;
        // cout << js[i].subtitle << endl;
        // cout << js[i].name << endl;
        // cout << js[i].vol << endl;
        // cout << js[i].issue << endl;
        // cout << js[i].year << endl;
    }

    sort(js.begin(), js.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << "title: " << js[i].title << '\n';
        cout << "subtitle: " << js[i].subtitle << '\n';
        printf("journal info\n");
        cout << "_name: " << js[i].name << '\n';
        printf("_volume: %d\n", js[i].vol);
        printf("_issue: %d\n", js[i].issue);
        printf("_publication year: %d\n", js[i].year);

        if (i != n - 1) {
            printf("\n");
        }
    }

    return 0;
}
