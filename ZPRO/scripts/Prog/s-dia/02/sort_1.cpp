#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string lajna;
	vector<string> vstup;

	while (getline(cin, lajna))
	{
		vstup.push_back(lajna);
	}

	sort(vstup.begin(), vstup.end());

	for (string ��dek : vstup)
		cout << ��dek << endl;
}