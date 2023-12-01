#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = " ";
    string cmp = "Kim";

    if (seoul.empty())
    {
        return answer;
    }

    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i].compare(cmp) == 0)
            answer = "김서방은 " + to_string(i) + "에 있다.";
    }
   

    return answer;
}

void main()
{
    vector<string> seoul;
  
    seoul.push_back("Jane");
    seoul.push_back("Kim");
    seoul.push_back("asdf");
    seoul.push_back("nlkfse");
    seoul.push_back("oiawnfe");

    cout << solution(seoul) << endl;

    seoul.clear();
    vector<string>().swap(seoul);
}