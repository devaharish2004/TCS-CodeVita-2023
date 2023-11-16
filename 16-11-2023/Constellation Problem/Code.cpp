// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    //Constellation Problem
    int cols;
    cin >> cols;
    int rows = 3;
    char mat[rows][cols];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    int index = 0;
    while(index < cols)
    {
        char val = mat[0][index];
        if(val == '#')
        {
            cout << '#';
            index++;
        }
        else if(val == '.')
        {
            if(mat[1][index] == '.' && mat[2][index] == '.')
            {
                index++;
            }
            else
            {
                cout << 'A';
                index += 3;
            }
        }
        else //val is a star
        {
            if(mat[1][index] == '.')
            {
                cout << 'I';
            }
            else if(mat[0][index+1] == '.')
            {
                cout << 'U';
            }
            else if(mat[1][index+1] == '.')
            {
                cout << 'O';
            }
            else
            {
                cout << 'E';
            }
            index += 3;
        }
    }
    

    return 0;
}