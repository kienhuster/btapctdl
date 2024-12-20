#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

struct List{
    node* head;
};

void list(List* l){
    l->head = NULL;
}

node* makenode(int x){
    node* newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

// Thêm node vào đầu danh sách
void them_node_dau(List* l, int x){
    node* newnode = makenode(x);
    newnode->next = l->head;   
    l->head = newnode; 
}

// Thêm node vào cuối danh sách
void them_node_cuoi(List* l, int x){
    node* newnode = makenode(x);
    
    if(l->head == NULL){
        l->head = newnode;
        return;
    }
    node* temp = l->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

// Hàm tính kích thước
int size(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Thêm node vào giữa danh sách
void them_node_giua(List* l, int x, int k){
    int n = size(l->head);
    if(k < 1 || k > n + 1) return;
    
    if(k == 1){
        them_node_dau(l, x);
        return;
    }
   
    node* newnode = makenode(x);
    node* temp = l->head;
    for(int i = 0; i < k - 2; i++){ // Move to node before the k-th position
        temp = temp->next;
    }
    newnode->next = temp->next; // Link the new node to the next node
    temp->next = newnode; // Link the previous node to the new node
}

// Xóa node ở đầu danh sách
void xoa_node_dau(List* l){
    if(l->head == NULL) return;
    node* temp = l->head;
    l->head = l->head->next;
    delete temp;
}

// Xóa node ở cuối danh sách
void xoa_node_cuoi(List* l){
    if(l->head == NULL) return;

    node* temp = l->head;
    if(temp->next == NULL) {
        l->head = NULL;
        delete temp;
        return;
    }

    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    node* last = temp->next;
    temp->next = NULL;
    delete last;
}

// Xóa node ở giữa danh sách
void xoa_node_giua(List* l, int k){
    int n = size(l->head);
    if(k < 1 || k > n) return;
    
    if(k == 1) {
        xoa_node_dau(l);
        return;
    }
    
    node* temp = l->head;
    for(int i = 0; i < k - 2; i++) {
        temp = temp->next;
    }
    node* middle = temp->next;
    temp->next = middle->next;
    delete middle;
}

// Hàm in danh sách
void print_list(List* l){
    node* temp = l->head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    List l;             // Tạo danh sách liên kết
    list(&l);           // Khởi tạo danh sách rỗng

    // Thêm node vào danh sách
    them_node_dau(&l, 10);
    them_node_cuoi(&l, 20);
    them_node_cuoi(&l, 30);
    them_node_giua(&l, 25, 3); // Thêm 25 vào vị trí thứ 3

    cout << "Danh sách sau khi thêm các node: ";
    print_list(&l);

    // Xóa node đầu
    xoa_node_dau(&l);
    cout << "Danh sách sau khi xóa node đầu: ";
    print_list(&l);

    // Xóa node cuối
    xoa_node_cuoi(&l);
    cout << "Danh sách sau khi xóa node cuối: ";
    print_list(&l);

    // Xóa node ở giữa
    xoa_node_giua(&l, 2);
    cout << "Danh sách sau khi xóa node ở vị trí 2: ";
    print_list(&l);

    return 0;
}
