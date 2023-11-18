#include <iostream>
using namespace std;

int combinations(int n, int r)
{
    //nCr formula
    long long num = 1, den = 1;
    for(int i = 1; i <= r; i++)
    {
        num *= n;
        den *= i;
        n--;
    }
    return num/den;
    
}

int main()
{
    int attendees, tables;
    cin >> attendees >> tables;
    cout << combinations(attendees,tables) << endl;
}