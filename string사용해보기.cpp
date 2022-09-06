#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str = "";
	getline(cin, str);

	for (int i = 0; i <= str.length(); i++)
	{
		cout << str << "\n";
		str += str.front();
		str = str.substr(1, str.length() + 1);
	}
}