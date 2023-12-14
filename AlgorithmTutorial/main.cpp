#include <string>
#include <iostream>

using namespace std;

string solution(string phone_number) {
	string answer = "";

	if (phone_number.length() > 4)
	{
		for (int i = 0; i < phone_number.length() - 4; i++)//뒤 4개를 제외한 길이만큼 *로 채워넣기
			answer += "*";
		answer += phone_number.substr(phone_number.length() - 4, 4);
	}

	return answer;
}

void main()
{
	cout << solution("nkldsflskdnf");
}