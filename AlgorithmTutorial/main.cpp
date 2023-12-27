#include <iostream>
#include <vector>

using namespace std;


//n만큼 알파벳을 뒤로 밀어서 다른 알파벳으로 바꾸는 함수
string solution(string str, int n) {
    string answer = "";

    for (char c : str)
    {
        if (c != ' ')//공백 제외
        {
            if (c + n > 122)//z를 넘어갔을 땐 다시 A로 돌아가서 시작
            {
                answer += 65 + (c + n - 123);
            }
            else
            {
                answer += c + n;
            }
        }
        else
        {//공백은 그대로 삽입
            answer += ' ';
        }
    }

    cout << answer;
    return answer;
}

void main()
{

    solution("aaf y", 2);
    
}