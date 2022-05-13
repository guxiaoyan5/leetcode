#include "iostream"
#include "vector"
#include <regex>
#include "deque"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return n;
        int temp1 = 1, temp2 = 2;
        int temp;
        int i = 3;
        while (i <= n) {
            temp = temp2 + temp1;
            temp1 = temp2;
            temp2 = temp;
            i++;
        }
        return temp;
    }
};

int main() {

}