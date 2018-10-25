// 从一头遍历，且交换次数多。

void realquicksort(int *a, int l, int r){
    int i, last;
    if(l < r){
        last = l;
        for(int i = l + 1; i <= r; i++){
            if(a[i] < a[l]){
                int tmp = a[++last];
                a[last] = a[i];
                a[i] = tmp;
            }
        }
        int tmp = a[l];
        a[l] = a[last];
        a[last] = tmp;
        realquicksort(a, l, last - 1);
        realquicksort(a, last + 1, r);
    }
}


// 从两头遍历，交换无显式交换。

int Partition(int *a, int l, int r){
    int last = a[l];
    while(l < r){
        while(l < r && a[r] >= last){
            r--;
        }
        if(l < r){
            a[l++] = a[r];
        }
        while(l < r && a[l] <= last){
            l++;
        }
        if(l < r){
            a[r--] = a[l];
        }
    }
    a[r] = last;
    return l;
}

void realquicksort2(int *a, int l, int r){
    if(l < r){
        int mid = Partition(a, l, r);
        realquicksort2(a, l, mid - 1);
        realquicksort2(a, mid + 1, r);
    }
}


// 主调用函数

void quicksort(int *a, int n){
    realquicksort(a, 0, n - 1);
}