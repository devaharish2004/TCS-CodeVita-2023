#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
        if(arr[i] < mini)
        {
            mini = arr[i];
        }
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    int effort = 2*arr[k-1]*mini + (maxi*mini);
    cout << effort;
}