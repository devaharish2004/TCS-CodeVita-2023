#include <iostream>
using namespace std;

int func(int start)
{
    if(start > 9999) return start;
    else
    {
        int digit = 0;
        int n = start;
        while(start > 0)
        {
            digit++;
            start /= 10;
        }
        for(int i = 0; i < 5-digit; i++)
        {
            cout << '0';
        }
        return n;
    }
}

int main()
{
    int n;
    cin >> n;
    int start = 6;
    int val = 0;
    for(int i = 0; i < n; i++)
    {
        for(int index = 0; index <= i; index++)
        {
            cout << func(start) << " ";
            start = start + (22 + (16*val));
            val++;
        }
        cout << endl;
    }

}