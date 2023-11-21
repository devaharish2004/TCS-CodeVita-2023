#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;



int bfs(int row, int col, vector<vector<string>>& arr, vector<vector<int>>& vis, int n)
{
    queue<pair<int,int>> q;
    q.push({row,col});
    vis[row][col] = 1;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        string s = arr[r][c];
        if(r == n-1 && c == n-1)
        {
            return 1;
        }
        for(int i = 0; i < s.length(); i++)
        {
            int nrow,ncol;
            if(s[i] == 'N')
            {
                nrow = r-1;
                ncol = c;

            }
            else if(s[i] == 'S')
            {
                nrow = r+1;
                ncol = c;
            }
            else if(s[i] == 'E')
            {
                nrow = r;
                ncol = c+1;
            }
            else if(s[i] == 'W')
            {
                nrow = r;
                ncol = c-1;
            }
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol] != 1 && arr[nrow][ncol] != "D")
            {
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;        
            }

        }
    }

    return 0;

}

void initialize(vector<vector<int>>&vis, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            vis[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> arr(n,vector<string>());

    vector<vector<int>> vis(n,vector<int>(n,0));
    
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        string s,t;
        getline(cin,s);
        stringstream X(s);
        while(getline(X,t,','))
        {
            arr[i].push_back(t);
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += bfs(0,i,arr,vis,n);
        initialize(vis,n);
    }

    for(int i = 1; i < n; i++)
    {
        ans += bfs(i,0,arr,vis,n);
        initialize(vis,n);
    }

    cout << ans << endl;  
}