#include<bits/stdc++.h>
using namespace std;

int main() {
    int sum, sum1, sum2, sum3, amount, n, hundred, twohundred, fivehundred, thousand, i, j, k, l, count = 0;

    cin >> n; // Maximum number of currency notes allowed to be withdrawn.
    cin >> amount; // The desired withdrawal amount (in multiples of 100).
    cin >> hundred; // Available currency notes of Rs 100.
    cin >> twohundred; // Available currency notes of Rs 200.
    cin >> fivehundred; // Available currency notes of Rs 500.
    cin >> thousand; // Available currency notes of Rs 1000.

    for (i = 0; i <= hundred; i++) {
        sum = i * 100;
        if (sum == amount && i <= n && i > count)
            count = i;
        if (sum < amount)
            for (j = 0; j <= twohundred; j++) {
                sum1 = sum + j * 200;
                if (sum1 == amount && (i + j) <= n && (j + i) > count)
                    count = i + j;
                if (sum1 < amount)
                    for (k = 0; k <= fivehundred; k++) {
                        sum2 = sum1 + k * 500;
                        if (sum2 == amount && (i + j + k) <= n && (i + j + k) > count)
                            count = i + j + k;
                        if (sum2 < amount)
                            for (l = 0; l <= thousand; l++) {
                                sum3 = sum2 + l * 1000;
                                if (sum3 == amount && (i + j + k + l) <= n && (i + j + k + l) > count)
                                    count = i + j + k + l;
                                if (sum3 > amount)
                                    l = thousand + 1; // Exit the loop if sum3 exceeds the desired amount.
                            }
                    }
            }
    }

    cout << count << endl; // Output the maximum possible currency note count.
    return 0;
}
