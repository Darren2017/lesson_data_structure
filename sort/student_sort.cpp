#include<iostream>
#include<iomanip>
#include<cstring>

#define RADIX 10

using namespace std;

typedef struct{
    string name, id;
    int score;
    int keys[10];
    int numkey;
}RcdType;

void RadixSort(RcdType s[], int cnt);
void RadixPass(RcdType A[], RcdType B[], int cnt, int i);

int main()
{
    int n, score;
    cout << "请输入学生人数n：" << endl;
    cin >> n;
    RcdType student[n];
    for(int i = 0; i < n; i++){
        cout << "请输入学生" << i + 1 << "的学号   名字   成绩" << endl;
        cin >> student[i].id >> student[i].name >> score;
        student[i].score = score;
        for(int j = 0; score; j++){
            student[i].keys[j] = score % 10;
            score /= 10;
        }
        student[i].numkey = 2;
    }
    RadixSort(student, n);
    cout << "学号 姓名 成绩" << endl;
    for(int i = n - 1; i >= 0; i--){
        cout << student[i].id << "   " << student[i].name << "   " << student[i].score <<  endl;
    }
    return 0;
}

void RadixSort(RcdType s[], int cnt){
    RcdType temstu[cnt];
    int i = s[0].numkey - 1;
    while(i >= 0){
        RadixPass(s, temstu, cnt, i);
        i--;
        if(i >= 0){
            RadixPass(temstu, s, cnt, i);
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
        count[A[k].keys[i]]++;
    }
    for(int j = 1; j < RADIX; j++){
        count[j] = count[j - 1] +count[j];
    }
    for(int k = cnt - 1; k >= 0; k--){
        int j = A[k].keys[i];
        B[count[j] - 1] = A[k];
        count[j]--;
    }
}