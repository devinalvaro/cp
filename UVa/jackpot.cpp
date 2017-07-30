/* dp : 1d range sum */
#include <algorithm>
#include <iostream>

int main()
{
    int n, a, ans, sum;
    std::cin >> n;

    while (n != 0) {
        ans = 0;
        sum = 0;

        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            sum += a;
            ans = std::max(ans, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        if (ans <= 0) {
            std::cout << "Losing streak." << std::endl;
        } else {
            std::cout << "The maximum winning streak is " << ans << '.'
                      << std::endl;
        }

        std::cin >> n;
    }
}
