#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Inputting variables
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> mat(n, vector<int>(m));

    // Inputting the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    unordered_map<string, int> map;

    // Storing frequency in map
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < m; j++) {
            temp += to_string(mat[i][j]);
        }

        // If map already contains that string increase the freq
        if (map.find(temp) != map.end()) {
            map[temp]++;
        } else {
            map[temp] = 1;
        }
    }

    int ans = INT_MIN;

    for (auto &entry : map) {
        // Counting number of zeros in each row
        int num_zeros = count(entry.first.begin(), entry.first.end(), '0');
        if (num_zeros <= k && (k - num_zeros) % 2 == 0) {
            ans = max(entry.second, ans);
        }
    }

    cout << "Maximum Rows that can be 1 are: " << ans << endl;

    return 0;
}
