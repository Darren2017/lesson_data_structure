#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> S;
    int N, M;
    cout << "分别输入要转换的数字和进制: ";
    cin >> N >> M;
    while(N){
        S.push(N % M);
        N /= M;
    }
    while(!S.empty()){
        cout << S.top();
        S.pop();
    }

    return 0;
}