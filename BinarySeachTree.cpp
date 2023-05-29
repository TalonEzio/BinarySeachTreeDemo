#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef Node* BinaryTree;
Node* CreateNode(int data)
{
    Node* pNode = new Node();
    pNode->data = data;
    pNode->pLeft = pNode->pRight = NULL;
    return pNode;
}
void InsertRecursion(BinaryTree& root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        return;
    }
    if (root->data == data) return;
    if (root->data < data)
    {
        InsertRecursion(root->pRight, data);
    }
    else
    {
        InsertRecursion(root->pLeft, data);
    }
}
void InsertNoRecursion(BinaryTree& root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        return;
    }
    if (root->data == data) return;


    Node* pTemp = root;
    Node* pParent = root;

    while (pTemp)
    {
        if (pTemp->data == data)return;

        pParent = pTemp;

        if (pTemp->data < data)
        {
            pTemp = pTemp->pRight;
        }
        else
        {
            pTemp = pTemp->pLeft;
        }
    }

    Node* pNewNode = CreateNode(data);
    if (pParent->data < data)
    {
        pParent->pRight = pNewNode;
    }
    else
    {
        pParent->pLeft = pNewNode;
    }

}
void PreOrder(BinaryTree root)
{
    if (root)
    {
        cout << root->data << " ";
        PreOrder(root->pLeft);
        PreOrder(root->pRight);
    }
}

void InOrder(BinaryTree root)
{
    if (root)
    {
        InOrder(root->pLeft);
        cout << root->data << " ";
        InOrder(root->pRight);
    }
}

void PostOrder(BinaryTree root)
{
    if (root)
    {
        PostOrder(root->pLeft);
        PostOrder(root->pRight);
        cout << root->data << " ";
    }
}


Node* SearchNode(BinaryTree root, int data)
{
    if (root == nullptr || root->data == data)return root;
    if (root->data < data)
    {
        return SearchNode(root->pRight, data);
    }
    return SearchNode(root->pLeft, data);
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây con bên trái của nút cần xóa
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->pLeft != nullptr)
        current = current->pLeft;
    return current;
}
// Hàm xóa nút trong cây nhị phân tìm kiếm
Node* deleteNode(BinaryTree& root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) 
        root->pLeft = deleteNode(root->pLeft, key);
    else if (key > root->data) 
        root->pRight = deleteNode(root->pRight, key);
    else {
        if (root->pLeft == nullptr) {
            Node* temp = root->pRight;
            delete root;
            return temp;
        }
        else if (root->pRight == nullptr) {
            Node* temp = root->pLeft;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->pRight);
        root->data = temp->data;
        root->pRight = deleteNode(root->pRight, temp->data);
    }
    return root;
}
int main()
{
    BinaryTree root = NULL;
    InsertRecursion(root,15);
    InsertRecursion(root, 7);
    InsertRecursion(root, 13);
    InsertRecursion(root, 9);
    InsertRecursion(root, 6); 
    InsertRecursion(root, 17);
    InsertRecursion(root, 16);
    InsertRecursion(root, 20);

    deleteNode(root, 9);

    PreOrder(root); cout << endl;
    InOrder(root); cout << endl;
    PostOrder(root); cout << endl;


    /*cout << "No recursion!\n";
    BinaryTree root2 = NULL;
    InsertNoRecursion(root2, 15);
    InsertNoRecursion(root2, 7);
    InsertNoRecursion(root2, 13);
    InsertNoRecursion(root2, 6);
    InsertNoRecursion(root2, 17);
    InsertNoRecursion(root2, 16);
    InsertNoRecursion(root2, 20);

    PreOrder(root2); cout << endl;
    InOrder(root2); cout << endl;
    PostOrder(root2); cout << endl;*/
  
    
    system("pause");
}
