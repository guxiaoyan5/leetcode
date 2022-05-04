#include "algorithm"
#include "iostream"
#include "vector"
#include "stack"
#include "map"
#include "set"

using namespace std;

class Solution {
public:

    bool dfs(map<int, int> &m, vector<int> &key, vector<vector<int>> &results, vector<int> &result, int i, int s,
             int target) {
        if (s == target) {
            results.push_back(result);
            return false;
        } else if (s > target) {
            return false;
        } else if (i >= m.size()) {
            return true;
        } else {
            int j = 0;
            int k = (target - s) / key[i];
            bool flag = true;
            for (; j < k + 1 && j < m[key[i]] && flag; ++j) {
                flag = dfs(m, key, results, result, i + 1, s + j * key[i], target);
                if (j != 0) result.push_back(key[i]);
            }
            for (int l = 1; l < j; ++l) {
                result.pop_back();
            }
        }
        return true;
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        map<int, int> m;
        vector<int> key;
        for (int i = 0; i < candidates.size(); ++i) {
            if (m.count(candidates[i]) == 0) {
                m[candidates[i]] = 1;
                key.push_back(candidates[i]);
            } else {
                m[candidates[i]] += 1;
            }
        }
        sort(key.begin(), key.end());
        dfs(m,key,results,result,0,0,target);
        return results;
    }
};


int main() {

}