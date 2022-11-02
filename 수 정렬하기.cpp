#include <iostream>
using namespace std;

int main(void) 
{
	int a[1000], i, j, n, temp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[i] = temp;
	}

	for (i = n; i > 0; i--) {
		for (j = 0; j < i-1; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}