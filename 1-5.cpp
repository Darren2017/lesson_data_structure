#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, x, sp, P = 0, a[1000];
    cin >> n >> x;
    sp = x;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 0; i <= n; i++){
        P = P + a[i] * sp;
        sp = P;
    }

}