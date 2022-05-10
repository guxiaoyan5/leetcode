#include "algorithm"
#include "iostream"
#include "vector"
#include "stack"
#include "map"
#include "set"

using namespace std;

class Solution {
public:
    void dfs(int i, int n, vector<bool> &visited,vector<bool> &left ,vector<bool> &right,vector<int> &queen, int &results) {
        if (i == n) {
            results+=1;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!visited[j] &&!right[i+j] &&!left[n-i+j-1]) {
                visited[j] = true;
                right[i+j] = true;
                left[n-i+j-1] = true;
                queen[i] = j;
                dfs(i+1, n, visited,left,right, queen, results);
                visited[j] = false;
                right[i+j] = false;
                left[n-i+j-1] = false;
                queen[i] = -1;
            }
        }
    }

    int totalNQueens(int n) {
        vector<bool> visited(n, false);
        vector<bool> left(2 * n - 1, false);
        vector<bool> right(2 * n - 1, false);
        vector<int> queen(n, -1);
        int results = 0;
        dfs(0, n, visited,left,right, queen, results);
        return results;
    }
};

int main() {
}
