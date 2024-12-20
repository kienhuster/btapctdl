#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

/*struct List {
    Node* head;
};

void initializeList(List* l) {
    l->head =NULL;
}*/

Node* makeNode(string x) {
    Node* newnode = new Node();
    newnode->data = x;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}
bool Isempty(Node*Head){
    return Head==NULL;
}
Node* binaryTree() {
    string x;
    
    getline(cin, x);

    // Điều kiện dừng đệ quy
    if (x == "null") {
        return nullptr;
    }

    // Tạo node mới
    Node* newnode = makeNode(x);

    // Xây dựng cây nhị phân
    cout << "Node trái của " << x << ": " << endl;
    newnode->left = binaryTree();

    cout << "Node phải của " << x << ": " << endl;
    newnode->right = binaryTree();

    return newnode;
}
//Ham hậu tố
void LRN(Node*Head){
    
    if(Isempty(Head))  return ;//hàm rỗng chỉ gọi khi xảy
    LRN(Head->left);
    LRN(Head->right);
    cout<<Head->data;
}
//Hàm trung tố
void LNR(Node*Head){
    if(Isempty(Head))return;
    LNR(Head->left);
    cout<<Head->data;
    LNR(Head->right);
}
//Hàm tiền tố
void NLR(Node*Head){
    if(Isempty(Head)) return;
    cout<<Head->data;
    NLR(Head->left) ;
    NLR(Head->right) ;
}

int main() {
    cout << "Nhập đỉnh cây: ";
    /*List l;
    initializeList(&l);*/
    Node*head;
    head = binaryTree();
    cout<<"hau to: ";
    LRN(head);
    cout<<endl<<"Trung to: ";
    LNR(head);
    cout<<endl<<"Tien to: ";
    NLR(head);
    return 0;
}
