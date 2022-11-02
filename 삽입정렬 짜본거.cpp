#include <iostream>
using namespace std;

int  a[1000000];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i, j, n, temp, val;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> temp;
		a[i] = temp;
	}

	for (i = 0; i < n-1; i++) {
		val = i;
		for (j = i+1; j > 0; j--) {
			if (a[val] > a[j])
			{
				temp = a[val];
				a[val] = a[j];
				a[j] = temp;
			}
			val--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
}