#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int o = 0;
    int e = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(i%2 == 0)
        {
            e += v[i];
        }
        else
        {
            o += v[i];
        }
    }

    cout << max(e,o) << endl;

    return 0;
}