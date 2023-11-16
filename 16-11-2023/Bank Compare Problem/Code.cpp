// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
using namespace std;

double findEMI(ll principal, double interest_rate, ll years)
{
     return principal * interest_rate / ( 1 - 1 / pow((1 + interest_rate),years*12));
}

int main() {
    // Write C++ code here
    //inputs
    ll principal;
    cin >> principal;
    ll tenure;
    cin >> tenure;
    int n1;
    cin >> n1;
    double EMI_A = 0;
    for(int i = 0; i < n1; i++)
    {
        ll years;
        cin >> years;
        double interest_rate;
        cin >> interest_rate;
        
        EMI_A += findEMI(principal, interest_rate, years);
    }
    int n2;
    cin >> n2;
    double EMI_B = 0;
    for(int i = 0; i < n1; i++)
    {
        ll years;
        cin >> years;
        double interest_rate;
        cin >> interest_rate;
        
        EMI_B += findEMI(principal, interest_rate, years);
    }
    
    if(EMI_A <= EMI_B)
    {
        cout << "Bank A" << endl;
    }
    else
    {
        cout << "Bank B" << endl;
    }
    
    
    

    return 0;
}