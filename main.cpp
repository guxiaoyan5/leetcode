#include "iostream"
#include "vector"
#include <regex>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int flag = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int temp;
        while (i >= 0 && j >= 0) {
            temp = a[i] + a[j] - '0' - '0' + flag;
            flag = temp / 2;
            result.insert(result.begin(), 1, temp % 2 + '0');
            i--;
            j--;
        }
        while (i >= 0) {
            temp = a[i]  - '0' + flag;
            flag = temp / 2;
            result.insert(result.begin(), 1, temp % 2 + '0');
            i--;
        }
        while (j >= 0) {
            temp = a[j]  - '0' + flag;
            flag = temp / 2;
            result.insert(result.begin(), 1, temp % 2 + '0');
            j--;
        }
        if(flag==1) result.insert(result.begin(), 1, '1');
        return result;
    }
};

int main() {

}