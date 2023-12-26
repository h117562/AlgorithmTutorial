#include <iostream>
#include <vector>

using namespace std;


void PrintPlayers(std::vector<string> players)
{
    for (string name : players)
    {
        cout << name << ", ";
    }

    cout << endl;

    return;
}

void solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    answer = players;

    if (callings.size() > 0)
    {
        for (int i = 0; i < callings.size(); i++)
        {
            int x = 0;
            for (string name : answer)
            {
                if (name == callings[i])
                {
                    answer.erase(answer.begin() + x);//앞에서 x번째 요소 제거
                    answer.insert(answer.begin(), name);

                    PrintPlayers(answer);
                }

                x++;
            }
        }
    }

    cout << "result : ";
    PrintPlayers(answer);
    return;
}

//중복이름 금지, 관련 처리 없음
int main()
{
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> call = { "kai", "kai", "mine", "mine" };

    solution(players, call);


    return 0;
}