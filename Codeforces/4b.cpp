#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int d, sumTime;
    cin >> d >> sumTime;

    int minTime[d], maxTime[d], studyTime[d];
    int minTimeSum = 0, maxTimeSum = 0;

    for (int i = 0; i < d; i++) {
        cin >> minTime[i] >> maxTime[i];

        minTimeSum += minTime[i];
        maxTimeSum += maxTime[i];
    }

    if (sumTime < minTimeSum || sumTime > maxTimeSum) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < d; i++) {
        studyTime[i] = minTime[i];
        sumTime -= minTime[i];
    }
    for (int i = 0; i < d; i++) {
        if (sumTime == 0)
            break;
        int temp = min(sumTime, maxTime[i] - minTime[i]);
        studyTime[i] += temp;
        sumTime -= temp;
    }

    for (int i = 0; i < d; i++) {
        cout << (i == 0 ? "" : " ") << studyTime[i];
    }
    cout << endl;
}
