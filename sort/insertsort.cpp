void insertsort(int *a, int len){
    int i, j, key;
    for(i = 1; i < len; i++){
        key = a[i];
        for(j = i; j > 0 && key < a[j]; j--){
            a[j] = a[j - 1];
        }
        a[j] = key;
    }
}