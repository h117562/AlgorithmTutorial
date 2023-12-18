#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    string same[] = {"aya", "ye", "woo", "ma"};

    for (string obj : babbling)
    {
        int check = 0;

        for (string x : same)
        {
            if (obj.compare(x) >= 0)
            {
                check++;
            }
        }

        if (check == same->size() + 1)
        {
            answer++;
        }
    }

    return answer;
}


void main()
{
    vector<string> str = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };

    cout << solution(str);
}