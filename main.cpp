#include <unordered_map>
#include "algorithm"
#include "iostream"
#include "vector"
#include "map"

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
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> allWordsMap;
        for (auto& v : words) {
            ++allWordsMap[v];
        }

        int num = words.size();
        int onelen = words[0].length();
        vector<int> res;
        if (s.length() < num * onelen) {
            return res;
        }

        for (int left = 0; left < s.length() - num * onelen + 1; ++left) {
            unordered_map<string, int> nowWordsMap;
            int right = left;
            while (right < left + num * onelen) {
                auto cur = s.substr(right, onelen);
                if (allWordsMap.find(cur) == allWordsMap.end()
                    || nowWordsMap[cur] == allWordsMap[cur]) {
                    break;
                }

                ++nowWordsMap[cur];
                right += onelen;
            }

            if (right == left + num * onelen) {
                res.emplace_back(left);
            }
        }

        return res;
    }
};

int main() {

}