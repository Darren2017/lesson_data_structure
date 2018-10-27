#include<iostream>
#include<cstring>

using namespace std;


double binaryKnapsack(int numItems, int *w, double *v, int capacity){
    double val[capacity + 1];
    memset(val, 0, sizeof(val));
    for(int i = 0; i < numItems; i++){
        for(int j = capacity; j >= 0; j--){
            if(j >= w[i] && val[j] < val[j - w[i]] + v[i]){
                val[j] = val[j - w[i]] + v[i];
            }
        }
    }
    return val[capacity];
}

int main()
{
    int i, n, C, w[100];
    double v[100];
    double ans;
    cin >> n >> C;
    for (i = 0; i < n; ++i)
        scanf("%d", &w[i]);
    for (i = 0; i < n; ++i)
        scanf("%lf", &v[i]);
    ans = binaryKnapsack(n, w, v, C);
    cout << ans << endl;
    return 0;
}