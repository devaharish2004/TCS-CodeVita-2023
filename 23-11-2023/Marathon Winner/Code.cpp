#include <iostream>
#include <vector>
#include <map>
using namespace std;

void check(vector<int>&ref, map<int,int>&mp)
{
    int val = INT_MIN;
    int index = -1;
    for(int i = 0; i < ref.size(); i++)
    {
        if(ref[i] > val)
        {
            val = ref[i];
        }
    }
    for(int i = 0; i < ref.size(); i++)
    {
        if(ref[i] == val)
        {
            mp[i]++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int time;
    cin >> time;

    int arr[n][time+1];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < time+1; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> ref(n,0);
    map<int,int>mp;
    for(int i = 0; i < time+1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ref[j] += (arr[j][i] * arr[j][time]);
        }
        if(i%2 == 1 && i != time-1)
        {
            check(ref,mp);
        }
    }
    int m = INT_MIN;
    for(auto it : mp)
    {
        if(it.second > m)
        {
            m = it.second;
        }
    }
    for(auto it : mp)
    {
        if(it.second == m)
        {
            cout << it.first+1 << endl;
            break;
        }
    }

}