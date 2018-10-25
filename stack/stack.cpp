#include"Stack_Sq.h"
#include<cstring>

int main()
{
    string input, output;
    SqStack S;
    SElemType tem;
    InitStack_Sq(S);
    cout << "请输入读入字符串：";
    cin >> input;
    cout << "请输入输入字符串：";
    cin >> output;
    int i = 0, j = 0, ilen = input.size(), olen = output.size();
    while(i < ilen || j < olen){
        if(GetTop_Sq(S, tem) && tem == output[j]){
            j++;
            Pop_Sq(S, tem);
        }else{
            Push_Sq(S, input[i++]);
        }
    }
    if(StackEmpty_Sq(S)){
        cout << "can" << endl;
    }else{
        cout << "can not" << endl;
    }

    return 0;
}