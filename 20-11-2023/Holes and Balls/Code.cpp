#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int holes, balls;
    cin >> holes >> balls;
    vector<int>h(holes),b(balls);
    for(int i = 0; i < holes; i++)
    {
        cin >> h[i];
    }
    for(int i = 0; i < balls; i++)
    {
        cin >> b[i];
    }

    reverse(h.begin(),h.end());
    vector<int>depth(holes,0);
    vector<int> ans;

    for(int i = 0; i < balls; i++)
    {
        int f = 0;
        for(int j = 0; j < holes; j++)
        {
            if(h[j] >= b[i] && depth[j] < holes-j)
            {
                depth[j]++;
                ans.push_back(holes-j);
                f = 1;
                break;
            }
            else
            {
                continue;
            }
        }
        if(f == 0) ans.push_back(0);
    }

    for(auto it : ans)
    {
        cout << it << " ";
    }

}