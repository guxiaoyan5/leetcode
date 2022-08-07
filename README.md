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




