# 第1823题
```c++
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        int i;
        int j = 0;
        while (q.size() != 1) {
            i = q.front();
            q.pop();
            j += 1;
            if (j % k != 0) {
                q.push(i);
            }
        }
        return q.front();
    }
};
```

#第75题
```c++
class Solution {
public:
    void sortColors(vector<int> &nums) {
        if(nums.size()==1) return;
        int left = 0, right = nums.size() - 1, temp = 0;
        int s;
        while(temp<=right && left<=right){
            if (nums[temp]==0){
                s = nums[temp];
                nums[temp] = nums[left];
                nums[left] = s;
                left++;
                temp++;
            }else if(nums[temp]==2){
                s = nums[temp];
                nums[temp] = nums[right];
                nums[right] = s;
                right--;
            }
            else{
                temp++;
            }
        }
    }
};
```

#第78题
```c++
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

```
#第94题
```c++
class Solution {
public:
    void order(vector<int> &result,TreeNode *root){
        if(root== nullptr) return;
        if(root->left!= nullptr) order(result,root->left);
        result.push_back(root->val);
        if(root->right!= nullptr) order(result,root->right);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        order(result,root);
        return result;
    }
};
```

#第92题
```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = 0;
        vector<vector<int>> left(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    if (j != 0) left[i][j] = left[i][j - 1] + 1;
                    else  left[i][j] = 1;
                    if (i == 0) m = max(m, left[i][j]);
                    else {
                        int z=left[i][j];
                        for (int k = i; k >= 0; --k) {
                            z = min(z,left[k][j]);
                            m = max(m, z * (i - k + 1));
                        }
                    }
                }
            }
        }
        return m;
    }
};
```