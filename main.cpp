#include "algorithm"
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                char d = st.top();
                if ((s[i] == ')' && d == '(') || (s[i] == ']' && d == '[') || (s[i] == '}' && d == '{')) {
                    continue;
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {

}