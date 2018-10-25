#include"Stack_Sq.h"

bool OpMember(char ch);
bool precede(char currOper, char topOper);

char tmp;

void transform(char suffix[], char exp[]){
    SqStack S;
    InitStack_Sq(S);
    tmp = '#';
    Push_Sq(S, tmp);
    char *p = exp, ch = *p;
    int k = 0;
    while(!StackEmpty_Sq(S)){
        if(!OpMember(ch)){
            suffix[k++] = ch;
        }else{
            switch(ch){
                case '(':{
                    Push_Sq(S, ch);
                    break;
                }
                case ')':{
                    Pop_Sq(S, tmp);
                    while(tmp != '('){
                        suffix[k++] = tmp;
                        Pop_Sq(S, tmp);
                    }
                    break;
                }
                default:{
                    while(GetTop_Sq(S, tmp) && (precede(tmp, ch))){
                        suffix[k++] = tmp;
                        Pop_Sq(S, tmp);
                    }
                    if(ch != '#'){
                        Push_Sq(S, ch);
                    }
                    break;
                }
            }
        }
        if(ch != '#'){
            ch = * ++p;
        }
    }
    suffix[k] = '\0';
}

bool OpMember(char ch){
    string opers = "+-*/()";
    for (int i = 0; i < opers.size(); i++) {
        if (ch == opers[i]){
            return true;
        }
    }
    return false;
}

bool precede(char currOper, char topOper){
    if (currOper == '+' || currOper == '-') {
        if (topOper == '*' || topOper == '/' || topOper == '+' || topOper == '-') {
            return true;
        }
    }

    if (currOper == '*' || currOper == '/') {
        if (topOper == '*' || topOper == '/') {
            return true;
        }
    }

    return false;
}

int main() {
    char infix[200], suffix[200];
    //输入的字符串不能有空格
    cin>>infix;
    transform(suffix, infix);
    cout << suffix << endl;
    
    return 0;
}