#include <iostream>
using namespace std;

// Cấu trúc một node trong danh sách móc nối biểu diễn đa thức
struct Node_dt {
    float heso;      // Hệ số của đa thức
    int somu;        // Số mũ của đa thức
    Node_dt* next;   // Con trỏ trỏ tới phần tử tiếp theo
};

// Cấu trúc của danh sách móc nối
struct DanhSach {
    Node_dt* first;  // Con trỏ tới phần tử đầu tiên
    Node_dt* last;   // Con trỏ tới phần tử cuối cùng
};

// Khởi tạo danh sách
void List_Init(DanhSach* list) {
    list->first = list->last = nullptr;
}

// Tạo một node mới
Node_dt* createNode(float a, int n) {
    Node_dt* p = new Node_dt;
    if (p == nullptr) return nullptr;
    p->heso = a;
    p->somu = n;
    p->next = nullptr;
    return p;
}

// Thêm một node vào cuối danh sách
void addNode(DanhSach* ds, Node_dt* p) {
    if (ds->first == nullptr) {
        ds->first = ds->last = p;
    } else {
        ds->last->next = p;
        ds->last = p;
    }
}

// Hàm tiện ích để thêm phần tử với hệ số và số mũ cụ thể
void attachNode(DanhSach* ds, float hs, int sm) {
    Node_dt* p = createNode(hs, sm);
    if (p != nullptr) {
        addNode(ds, p);
    }
}

// Tạo đa thức f(x) và g(x)
void createPolynomials(DanhSach* f, DanhSach* g) {
    attachNode(f, 1, 10);   // f(x) = x^10 + 1
    attachNode(f, 1, 0);

    attachNode(g, 1, 15);   // g(x) = x^15 + x^10 + x^7 + x^5 + x^2 + 1
    attachNode(g, 1, 10);
    attachNode(g, 1, 7);
    attachNode(g, 1, 5);
    attachNode(g, 1, 2);
    attachNode(g, 1, 0);
}

// Hàm in danh sách biểu diễn đa thức
void printList(DanhSach* ds) {
    Node_dt* current = ds->first;
    while (current != nullptr) {
        cout << current->heso << "x^" << current->somu;
        if (current->next != nullptr) cout << " + ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    DanhSach f, g;
    List_Init(&f);
    List_Init(&g);

    // Tạo hai đa thức f(x) và g(x)
    createPolynomials(&f, &g);

    // In ra đa thức f(x) và g(x)
    cout << "Da thuc f(x): ";
    printList(&f);
    cout << "Da thuc g(x): ";
    printList(&g);

    return 0;
}
