#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            answer += i;
        }
    }

    return answer;
}

void main()
{
    cout << solution(8);
}