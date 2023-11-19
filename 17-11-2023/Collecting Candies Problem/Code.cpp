#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int val1 = arr[0];
        int val2 = 0;
        for(int i = 0; i < n-1; i++)
        {
            val1 += arr[i+1];
            val2 += val1;
        }
        cout << val2 << endl;
    }
}