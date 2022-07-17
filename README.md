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