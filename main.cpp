#include "algorithm"
#include "iostream"
#include "vector"
#include "stack"
#include "map"
#include "set"

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        if (matrix.size() == 1) return;
        int n = matrix.size(), s = n % 2;
        int temp;
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < n - 1 - 2 * i; ++j) {
                temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[n-1-i-j][i];
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i] = temp;
            }
        }
    }
};

int main() {

}
