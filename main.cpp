//
// Created by 17302 on 2022/9/1.
//
#include "iostream"
using namespace std;
struct stru{
    char c;
    int a;
};
union uni{
    char c;
    int a;
};
void func(struct stru arr[2]){
    const char *str = "hello";
    char str2[] = "he";
    struct stru st= {0};
    union uni un= {0};
}
int main(){
    cout<<
    return 0;
};