#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for (int a : arr)
    {
        answer += a;
    }

    answer /= arr.size();

    return answer;
}

void main()
{
    vector<int> arr = { 1,2,3,4 };

    cout << solution(arr) << endl;
}