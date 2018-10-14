#include"List_Sq.h"

#define RcdType int
#define random(x) (rand()%x)

void QuickSort(SqList &L);
void Qsort(RcdType R[], int s, int t);
int Partition(RcdType R[], int low, int high);
ElemType get_mid(ElemType a, ElemType b, ElemType c);


int main()
{
    SqList La;
    InitList_Sq(La);
    for(int i = 1; i <= 30; i++){
        ListInsert_Sq(La, i, random(536));
    }
    QuickSort(La);
    ListTraverse_Sq(La);
    DestroyList_Sq(La);
    return 0;
}


void QuickSort(SqList &L){
    Qsort(L.elem, 0, L.length - 1);
}

void Qsort(RcdType R[], int s, int t){
    if(s < t){
        int mid = Partition(R, s, t);
        Qsort(R, s, mid - 1);
        Qsort(R, mid + 1, t);
    }
}

int Partition(RcdType R[], int low, int high){
    ElemType rec = R[low];
    while(low < high){
        while(low < high && R[high] >= rec){
            high--;
        }
        if(low < high){
            R[low++] = R[high];
        }
        while(low < high && R[low] <= rec){
            low++;
        }
        if(low < high){
            R[high--] = R[low];
        }
    }
    R[low] = rec;
    return low;
}

ElemType get_mid(ElemType a, ElemType b, ElemType c){
    return (a < b ? (b < c ? b : a < c ? c : a) : (b > c ? b : a > c ? c : a));
}