// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<int>arrival(n), departure(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arrival[i] >> departure[i];
        departure[i] += arrival[i];
    }
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int i = 1;
    int j = 0;
    int platforms = 1;
    int max_val = 1;
    while(i < n && j < n)
    {
        if(arrival[i] <= departure[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        if(platforms > max_val)
        {
            max_val = platforms;
        }
    }
    
    cout << max_val << endl;
    
    return 0;
}