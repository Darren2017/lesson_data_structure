#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int len = s.size();
        if(s.size() % 2){
            return false;
        }
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                S.push(s[i]);
            }else if(S.empty()){
                return false;
            }else if(s[i] == ')' && S.top() != '('){
                return false;
            }else if(s[i] == ']' && S.top() != '['){
                return false;
            }else if(s[i] == '}' && S.top() != '{'){
                return false;
            }else{
                S.pop();
            }
        }
        if(S.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    string input;
    cout << "请输入括号组合:   ";
    cin >> input;
    Solution solution;
    bool ans = solution.isValid(input);
    if(ans){
        cout << "can";
    }else{
        cout << "can not";
    }

    return 0;
}