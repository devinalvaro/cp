/* brute force : recursive backtracking */

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
bool match;
bool bits[11][8];

int isSame(bool bit[], bool ori[])
{
    for (int i = 1; i <= 7; i++)
        if (bit[i] != ori[i]) {
            return false;
        }

    return true;
}

void genLED(bool bit[], int n)
{
    for (int i = 0; i <= 7; i++) {
        bit[i] = 1;
    }

    if (n == 9) {
        bit[5] = 0;
    }

    if (n == 7) {
        bit[4] = bit[5] = bit[6] = bit[7] = 0;
    }

    if (n == 6) {
        bit[2] = 0;
    }

    if (n == 5) {
        bit[2] = bit[5] = 0;
    }

    if (n == 4) {
        bit[1] = bit[4] = bit[5] = 0;
    }

    if (n == 3) {
        bit[5] = bit[6] = 0;
    }

    if (n == 2) {
        bit[3] = bit[6] = 0;
    }

    if (n == 1) {
        bit[1] = bit[4] = bit[5] = bit[6] = bit[7] = 0;
    }

    if (n == 0) {
        bit[7] = 0;
    }
}

bool checkBurn(bool bit[], bool burned[])
{
    for (int i = 1; i <= 7; i++)
        if (bit[i] == 1 && burned[i] == 1) {
            return false;
        }

    return true;
}

bool isDeriv(bool bit[], int n, bool burned[])
{
    bool ori[8], mod[8];
    genLED(ori, n);

    for (int i = 0; i <= 7; i++) {
        mod[i] = bit[i] | ori[i];
    }

    if (isSame(mod, ori)) {
        for (int i = 1; i <= 7; i++)
            if (bit[i] == 0 && ori[i] == 1) {
                burned[i] = 1;
            }

        return true;
    } else {
        return false;
    }
}

void backtrack(int index, int threshold, bool burned[])
{
    if (index >= n) {
        match = true;
    }

    bool burnedCopy[8];

    for (int i = 0; i <= 7; i++) {
        burnedCopy[i] = burned[i];
    }

    if (threshold >= 0 && !match) {
        if (isDeriv(bits[index], threshold, burned) &&
            checkBurn(bits[index], burned)) {
            backtrack(index + 1, threshold - 1, burned);
        }

        backtrack(0, threshold - 1, burnedCopy);
    }
}

int main()
{
    string s;
    cin >> n;

    while (n != 0) {
        for (int i = 0; i <= 10; i++)
            for (int j = 0; j <= 7; j++) {
                bits[i][j] = 0;
            }

        for (int i = 0; i < n; i++) {
            cin >> s;

            for (int j = 0; j < 7; j++)
                if (s[j] == 'Y') {
                    bits[i][j + 1] = 1;
                }
        }

        match = false;
        bool burned[8];

        for (int i = 0; i <= 7; i++) {
            burned[i] = 0;
        }

        backtrack(0, 9, burned);

        if (match) {
            cout << "MATCH\n";
        } else {
            cout << "MISMATCH\n";
        }

        cin >> n;
    }
}
