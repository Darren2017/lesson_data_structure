// // #include"Queue_Sq.h"
// #include"Queue_L.h"

// int main()
// {
//     LinkQueue Q;
//     InitQueue_L(Q);
//     for(int i = 0; i < 105; i++){
//         EnQueue_L(Q, i + 1);
//     }
//     int a[109];

//     QueueTraverse_L(Q);

//     for(int i = 0; !QueueEmpty_L(Q); i++){
//         DeQueue_L(Q, a[i]);
//     }

//     cout << endl << endl;
//     for(int i = 0; i < 105; i++){
//         cout << a[i] << "  ";
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

void sw(int *a[], int s, int b[])
{
	for (int i=0; i < s; i++){
		for (int j=0; j<b[s]; j++)
			for (int k=j+1, h; k<b[s]; k++)
				if (abs(a[i][j]) > abs(a[i][k])) {
					h = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = h;
				}
	}

}

/*int abs(int x)
{
	if (x < 0) return -x;
	else return x;
}*/

int main()
{
	int a[100][100], n, s=0, b[100];
	int check;

	do {
		scanf("%d", &n);
		if (n > 100 || n < 0) puts("ERROR!");
		else {
			for (; b[s] < n; ++b[s]) {
				scanf("%d", &a[s][b[s]]);
				for (int i=0; i < b[s]; i++)
					if ( abs( a[s][i] ) == abs( a[s][b[s]] ) )
						goto error;
			}
			if (n != 0) s++;
		}
		error: puts("ERROR!");
	} while (n != 0);

	sw(a, s, b);

	for (int i=0; i < s; i++) {
		for (int j=0; j < b[s]; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}

	return 0;
}