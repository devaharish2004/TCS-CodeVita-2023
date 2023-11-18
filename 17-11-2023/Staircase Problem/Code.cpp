#include <iostream>
using namespace std;

int solve(int n)
{
    if(n <= 3)
    {
        return n;
    }
    return solve(n-1) + solve(n-2);
}

int main()
{
    int n; //No.of stairs
    cin >> n;
    cout << solve(n) << endl;
}