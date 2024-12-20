// xếp gỗ
#include<iostream>
#include<string>
#define MAX 100 // số phần tử tối đa trong stack
using namespace std;
struct wood {
    string type;   
    int size, age;
};
// cài đặt cấu trúc của stack
struct store{
 int top;  // phần tử xác định ngăn xếp 
 wood Data[MAX];
};
// khởi tạo ngăn xếp
void Init(store*kho){
  kho->top =0;
  }
 // kiểm tra ngăn xếp rỗng
int Isempty(store kho){
    return (kho.top==0);
}
//Kiem tra ngan xem đầy
int Isfull(store kho){
    return(kho.top== MAX );
}
//Hàm thêm phần tử vào ngăn xếp(xếp gỗ vào kho)
void Push(store& kho,wood x){
    if(Isfull(kho)){
        cout<<"Kho day !";
    }
    else{
        kho.top++;
        kho.Data[kho.top]= x;
    }
}
// Hàm lấy phần tử khoi dau ngăn xếp
wood Pop(store& kho){
    if(Isempty(kho)){
        cout<<endl<<"Kho khong co go !"<<endl;
    } 
    else{
        wood x = kho.Data[kho.top];
        kho.top--;
        return x;
    }
}
// Hàm nhập
void Input(store& kho){
    wood x;
    cin>>x.type >>x.size >>x.age;
    Push(kho,x);
}
void Output(store kho) {
    cout << "Thông tin gỗ trong kho:" << endl;
    while (kho.top!=0) {
        wood x = Pop(kho); // Lấy một phần tử gỗ từ stack
        cout << "Loại: " << x.type << ", Kích thước: " << x.size << ", Tuổi: " << x.age << endl;
    }
}
void chen_vao()

int main(){
    store kho;
    Init(&kho);
    for(int i=1;i < 5;i++){
        Input(kho);
    }
    Output(kho);
    return 0;
}