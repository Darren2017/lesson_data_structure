#include<iostream>
#include<iomanip>
#include<cstring>

#define RADIX 10

using namespace std;

typedef struct{
    string name, id, score;
    int keys[10];
    int numkey;
}RcdType;

void RadixSort(RcdType s[], int cnt);
void RadixPass(RcdType A[], RcdType B[], int cnt, int i);   //降序
void RadixPass2(RcdType A[], RcdType B[], int cnt, int i);  //升序

int main()
{
    int n, score;
    cout << "请输入学生人数n：" << endl;
    cin >> n;
    RcdType student[n];
    for(int i = 0; i < n; i++){
        cout << "请输入学生" << i + 1 << "的学号   名字   成绩" << endl;
        cin >> student[i].id >> student[i].name >> student[i].score;
        int len = student[i].score.size();
        for(int j = 0; j < len; j++){
            student[i].keys[j] = student[i].score[j];
        }
        student[i].numkey = len;
    }
    RadixSort(student, n);
    cout << "学号         姓名   成绩" << endl;
    for(int i = 0; i < n; i++){
        cout << student[i].id << "   " << student[i].name << "   " << student[i].score <<  endl;
    }
    return 0;
}

void RadixSort(RcdType s[], int cnt){
    RcdType temstu[cnt];
    int i = s[0].numkey - 1;
    while(i >= 0){
        RadixPass2(s, temstu, cnt, i);
        i--;
        if(i >= 0){
            RadixPass2(temstu, s, cnt, i);
            i--;
        }else{
            for(int j = 0; j < cnt; j++){
                s[j] = temstu[j];
            }
        }
    }
}

void RadixPass(RcdType A[], RcdType B[], int cnt, int i){
    int count[11];
    for(int j = 0; j < RADIX; j++){
        count[j] = 0;
    }
    for(int k = 0; k < cnt; k++){
        count[A[k].keys[i] - '0']++;
    }
    for(int j = 1; j < RADIX; j++){
        count[j] = count[j - 1] + count[j];
    }
    for(int k = cnt - 1; k >= 0; k--){
        int j = A[k].keys[i] - '0';
        B[count[j] - 1] = A[k];
        count[j]--;
    }
}

void RadixPass2(RcdType A[], RcdType B[], int cnt, int i){
    int count[11], num[10];
    for(int j = 0; j < RADIX; j++){
        count[j] = 0;
        num[j] = 0;
    }
    for(int k = 0; k < cnt; k++){
        count[A[k].keys[i] - '0']++;
        num[A[k].keys[i] - '0']++;
    }
    for(int j = RADIX - 2; j >= 0; j--){
        count[j] = count[j + 1] +count[j];
    }
    for(int j = 0; j < RADIX; j++){
        count[j] -= num[j] - 1;
    }
    for(int k = 0; k < cnt; k++){
        int j = A[k].keys[i] - '0';
        B[count[j] - 1] = A[k];
        count[j]++;
    }
}

/* 测试用例
4
2017211000 张三 072
2017211001 李四 382
2017211002 王五 083
2017211003 佚名 334
*/