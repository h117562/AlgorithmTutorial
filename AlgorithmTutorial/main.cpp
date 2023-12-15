#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = reserve.size();//체육복을 이미 갖고 있던 학생들 수 

    for (int n_lost : lost)
    {
        if (0 <= n_lost - 1)
        {
            for (int n_reserve : reserve)
            {
                if (n_reserve == n_lost - 1)//학생 앞 번호가 여분이 있을 때
                {
                    answer++;//체육복을 갖고 있는 학생 수 증가

                    break;
                }
                else if(n_reserve == n_lost + 1)//학생 뒷 번호가 여분이 있을 때
                {
                    answer++;//체육복을 갖고 있는 학생 수 증가

                    break;
                }
            }
        }


    }

    return answer;
}

//학생 번호는 1부터 시작 30이 최대
void main()
{
    vector<int> lost = { 2, 4 };
    vector<int> reserve = { 1,3,5 };

    int result = 0;
    result = solution(5, lost, reserve);
    cout << result;
}