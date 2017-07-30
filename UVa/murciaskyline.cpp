#include <iostream>
using namespace std;

int main()
{
    int t, tc = 0, n;

    cin >> t;

    while (t--) {
        cin >> n;

        int height[n], width[n];

        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> width[i];
        }

        int lisInc[n], lisDec[n];

        for (int i = 0; i < n; i++) {
            lisInc[i] = width[i];
            lisDec[i] = width[i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (height[i] > height[j] && lisInc[j] + width[i] > lisInc[i]) {
                    lisInc[i] = lisInc[j] + width[i];
                }

                if (height[i] < height[j] && lisDec[j] + width[i] > lisDec[i]) {
                    lisDec[i] = lisDec[j] + width[i];
                }
            }
        }

        int incLen = 0, decLen = 0;

        for (int i = 0; i < n; i++) {
            incLen = max(incLen, lisInc[i]);
            decLen = max(decLen, lisDec[i]);
        }

        cout << "Case " << ++tc << ". ";

        if (incLen >= decLen) {
            cout << "Increasing (" << incLen << "). Decreasing (" << decLen
                 << ").";
        } else {
            cout << "Decreasing (" << decLen << "). Increasing (" << incLen
                 << ").";
        }

        cout << '\n';
    }
}
