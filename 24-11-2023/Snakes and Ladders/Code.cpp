#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

pair<string,int> check(int val, string mat[][10])
{
    if(val == 100)
    {
        return {"End",0};
    }

    int row = -1;
    int col = -1;
    int count = 0;
    
    for(int i = 9; i >= 0; i--)
    {
        if(i%2 == 1)
        {
            for(int j = 0; j <= 9; j++)
            {
                
                count++;
                if(count == val)
                {
                    row = i;
                    col = j;
                    break;
                }
            }
            
        }
        else
        {
            for(int j = 9; j >= 0; j--)
            {
                
                count++;
                if(count == val)
                {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        if(row != -1 && col != -1)
        {
            break;
        }
    }

    string x = mat[row][col];

    if(x[0] == 'S')
    {
        size_t start = x.find('(');
        size_t end = x.find(')');
        string t = x.substr(start+1,end);
        
        int num = stoi(t);

        return {"Snake",num};
    }
    else if(x[0] == 'L')
    {
        int start = x.find('(');
        int end = x.find(')');
        string t = x.substr(start+1,end);
        int num = stoi(t);
        return {"Ladder",num};
    }
    else
    {
        return {"Integer",stoi(x)};
    }
}
int main()
{
    string mat[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> mat[i][j];
        }
    }


    int n;
    cin >> n;

    vector<int> steps(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> steps[i];
    }

    int count = 0;
    int snakes = 0;
    int ladders = 0;
    int flag = 0;

    for(int i = 0; i < n; i++)
    {
        count += steps[i];
       
        pair<string,int> ans = check(count,mat);

        
        if(ans.first == "End")
        {
            flag = 1;
            break;
        }
        else if(ans.first == "Snake")
        {
            snakes++;
            count = ans.second;

        }
        else if(ans.first == "Ladder")
        {
            ladders++;
            count = ans.second;
        }
     }
    if(flag == 0)
    {
        cout << "Not Possible "; 
    }
    else
    {
        cout << "Possible ";
    }
    cout << snakes << " " << ladders << " ";
    if(flag == 0)
    {   
        cout << count << endl;
    }
}