void bubblesort(int *a, int len){
    int i = len, lastExchangeIndex;
    while(i > 0){
        lastExchangeIndex = 0;
        for(int j = 0; j < i - 1; j++){
            if(a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                lastExchangeIndex = j + 1;
            }
        }
        i = lastExchangeIndex;
    }
}