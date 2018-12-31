#include"HuffmanTree.h"

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    // int n = 8, w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    int n, *w;
    cout << "请输入数据个数：";
    cin >> n;
    w = new int[n];
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    CreateHuffmanTree(HT, w, n);
    HuffmanCoding(HT, HC, n);
    for(int i = 0; i < n; i++){
        int j = 0;
        cout << char('a' + i) << ": ";
        while(HC[i][j]){
            cout << HC[i][j++] << " ";
        }
        cout << endl;
    }
    // for(int i = 0; i < 2 * n - 1; i++){
    //     cout << HT.HTree[i].weight << "  " << HT.HTree[i].lchild << "  " << HT.HTree[i].rchild << endl;
    // }
    return 0;
}