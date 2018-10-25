void merger(int a[], int L, int M, int R){
    int letf_size = M - L;
    int right_size = R - M + 1;
    int left[letf_size];
    int right[right_size];
    int i, k, j;

    for(i = L; i < M; i++){
        left[i - L] = a[i];
    }
    for(i = M; i <= R; i++){
        right[i - M] = a[i];
    }

    i = 0, k = L, j = 0;
    while(i < letf_size && j < right_size){
        if(left[i] < right[j]){
            a[k++] = left[i++];
        }else{
            a[k++] = right[j++];
        }
    }
    while(i < letf_size){
        a[k++] = left[i++];
    }
    while(j < right_size){
        a[k++] = right[j++];
    }
}

void realmergesort(int a[], int L, int R){
    if(L == R){
        return;
    }else{
        int M = (L + R) / 2;
        realmergesort(a, L, M);
        realmergesort(a, M + 1, R);
        merger(a, L, M + 1, R);
    }
}

void mergesort(int a[], int len){
    realmergesort(a, 0, len - 1);
}