#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int iter = 0;
int func(int i, int j, vector<string> mat[], int n) {
    iter++;
    // cerr << 2 << " ";
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (mat[i][j] == "D") {
        dp[i][j] = 0;
    }
    if (i == n - 1 and j == n - 1) {
        dp[i][j] = 1;
    } else {
        // cerr << 1 << " ";
        string s = mat[i][j];
        int q, w, e, r;
        q = w = e = r = 0;
        if (s.find("S") != string::npos) {
            q = func(i + 1, j, mat, n);
            // cerr << "fff";
        }
        if (s.find("W") != string::npos) {
            w = func(i, j - 1, mat, n);
        }
        if (s.find("E") != string::npos) {
            e = func(i, j + 1, mat, n);
        }
        if (s.find("N") != string::npos) {
            r = func(i - 1, j, mat, n);
        }
        dp[i][j] = (q | w | e | r);
    }
    return dp[i][j];
}

int main() {
    int n, cnt = 0;
    cin >> n;
    dp = vector(n, vector<int>(n, -1));
    vector<string> mat[n];

    for (auto &x : mat) {
        string s, temp;
        cin >> s;
        stringstream ss(s);
        vector<string> v;
        while (getline(ss, temp, ',')) {
            v.push_back(temp);
        }

        x = v;
    }

    for (int i = 0; i < n; i++) {
        func(0, i, mat, n);
        func(i, 0, mat, n);
    }

    for (auto x : dp) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        if (dp[0][n - i - 1] == 1) cnt++;
        if (dp[n - i - 1][0] == 1) cnt++;
    }

    if (dp[0][0] == 1) cnt--;
    cout << cnt;
    cerr << iter;
}