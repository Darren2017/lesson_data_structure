#include"Tree.h"

void visit(BiTNode *p);

int main()
{
    BiTree B = new BiTNode;
    InitBiTree(B);
    CreateBiTree(B);
    cout << "先序遍历：";
    Preorder(B, visit);
    cout << endl << "中序遍历：";
    InOrder_iter(B, visit);
    cout << endl << "后序遍历：";
    Postorder(B, visit);
    cout << endl << "层次遍历：";
    Hierarchical(B, visit);
    cout << endl;
    return 0;
}

void visit(BiTNode *p){
    cout << p -> data << "  ";
}