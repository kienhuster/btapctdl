#include<iostream>
using namespace std;

void daolai(int& x, int& y) {
	int c = x;
	x = y;
	y = c;
}
void nhap(int a[], int& n) {
	cout << "Nhap gia tri cua n: ";
	cin >> n;
	cout << "Nhap day gia tri: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void xuat(int a[], int& n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void selection_sort(int a[], int n) {

	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;

			}
		}
		daolai(a[min], a[i]);
		// In ra m?ng sau m?i bu?c hoán d?i
		xuat(a, n);
	}
}
void insertion_sort(int a[], int n) {

	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
		xuat(a, n);
	}
}
void bubble_sort(int a[], int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				daolai(a[j], a[j - 1]);
			}
		}
		xuat(a, n);
	}
}

int main() {
	int a[1000];
	int n;


	int choice;
	while (true) {

		cout << "Chon: ";
		cin >> choice;
		switch (choice) {
		case 1:
			nhap(a, n);
			selection_sort(a, n);
			break;
		case 2:
			nhap(a, n);
			insertion_sort(a, n);
			break;
		case 3:
			nhap(a, n);
			bubble_sort(a, n);
			break;
		}
	}
	return 0;
}