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

# 第2086题
```c++
class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (street[i] == 'H') {
                if (i + 1 < n && street[i + 1] == '.') {
                    ++ans;
                    // 直接跳过后续的两个位置
                    i += 2;
                }
                else if (i - 1 >= 0 && street[i - 1] == '.') {
                    ++ans;
                }
                else {
                    return -1;
                }
            }
        }
        return ans;
    }
};
```


