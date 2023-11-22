#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    count += n/10;
    n %= 10;
    count += n/7;
    n %= 7;
    count += n/5;
    n %= 5;
    count += n/1;
    n %= 1;
    cout << count << endl;
}