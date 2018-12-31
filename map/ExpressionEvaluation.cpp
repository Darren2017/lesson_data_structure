#include<iostream>
#include"h/Stack_Sq_for_exp.h"

using namespace std;

void transform(char suffix[], char exp[]);
bool OpMember(char ch);
bool preced(char a, char b);
double evaluation(char suffix[]);
double Operate(double a, char ch, double b);

int main()
{
    char suffix[40], exp[40];
    cin >> exp;
    transform(suffix, exp);
    cout << "后缀表达式：" << suffix << endl;
    cout << "计算结果：" << evaluation(suffix);
    return 0;
}


void transform(char suffix[], char exp[]){      //中缀表达式专后缀表达式
    char c = '#', *p = exp, ch = *p;
    int k = 0;
    SqStack S;
    InitStack_Sq(S);
    Push_Sq(S, c);
    while(!StackEmpty_Sq(S)){
        if(!OpMember(ch)){      //非操作符直接发送到后缀表达式
            suffix[k++] = ch;
        }else {
            switch (ch) {
                case '(' : {            //左括号直接进栈
                    Push_Sq(S, ch);
                    break;
                }
                case ')': {         //右括号，碰到做括号之前的所有操作符弹出
                    Pop_Sq(S, c);
                    while (c != '(') {
                        suffix[k++] = c;
                        Pop_Sq(S, c);
                    }
                    break;
                }
                default: {
                    while (GetTop_Sq(S, c) && preced(c, ch)) {          //取得栈顶操作符，如果优先级大于等于当前操作符则发送到后缀表达式
                        suffix[k++] = c;
                        Pop_Sq(S, c);
                    }
                    if (ch != '#') {        //取得栈顶操作符，如果优先级小于当前操作符则当前操作符入栈
                        Push_Sq(S, ch);
                    } else{                 //结束（此处书上有错
                        suffix[k++] = '#';  
                        Pop_Sq(S, c);
                    }
                    break;
                }
            }
        }
        if(ch != '#') {
            ch = *++p;
        }
    }
    suffix[k] = '\0';
}

bool OpMember(char ch){
    if(ch >= '0' && ch <= '9'){
        return false;
    }
    return true;
}

bool preced(char a, char b){            //判定优先级
    if(a == '#' || a == '('){
        return false;
    }
    if(a == '*' || a == '/'){
        return true;
    }
    if(b == '*' || b == '/'){
        return false;
    }
    return true;
}

double evaluation(char suffix[]){       //后缀表达式求值
    char ch = *suffix++;
    SqStack_d S;
    InitStack_Sq_d(S);
    while(ch != '#'){
        if(!OpMember(ch)){          //非操作符直接入栈
            double cchh = ch - '0';
            Push_Sq_d(S, cchh);
        }else{                      //遇到操作符弹出两个元素进行运算后入栈，注意先后顺序
            double a, b, c;
            Pop_Sq_d(S, b);
            Pop_Sq_d(S, a);
            c =  Operate(a, ch, b);
            Push_Sq_d(S, c);
        }
        ch = *suffix++;
    }
    double ans;
    Pop_Sq_d(S, ans);
    return ans;
}

double Operate(double a, char ch, double b){            //运算操作
    switch(ch){
        case '+':{
            return a + b;
        }
        case '-':{
            return a - b;
        }
        case '*':{
            return a * b;
        }
        case '/':{
            return a / b;
        }
    }
    return 0;
}

// 测试用例
// 3+(5+(7/4-6))*5#