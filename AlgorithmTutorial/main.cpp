#include <iostream>
#include <vector>

using namespace std;

void solution(int num1, int num2) {
	vector<vector<char>> stars;

	for (int y = 0; y < num1; y++)
	{
		stars.push_back(vector<char>());//열 추가

		for (int x = 0; x < num2; x++)
		{
			stars[y].push_back('*');
		}
	}


	for (int y = 0; y < stars.size(); y++)
	{
		for (int x = 0; x < stars[0].size(); x++)
		{
			cout << stars[y][x];
		}

		cout << endl;
	}


	stars.clear();
	vector<vector<char>>().swap(stars);
	return;
}

void main()
{
	int a, b = 0;

	cin >> a >> b;
	cout << a << ", " << b << endl;

	solution(a, b);

	return;
}