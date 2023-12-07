#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long temp = n;
    vector<int> ary;

    for (int i = 1000000000; i >= 1; i /= 10) //자리수 마다 구별하여 배열에 넣는다
    {
        if (temp % i != n)
        {
            ary.push_back(temp / i);
            temp %= i;
        }
    }


    for (int i = 0; i < ary.size() - 1; i++)//버블 정렬
    {
        for (int j = 1; j < ary.size() - i; j++)
        {
            if (ary[j - 1] < ary[j])//내림차 순
            {
                swap(ary[j - 1], ary[j]);
            }
        }
    }


    for (int i = 0; i < ary.size(); i++)
    {
        answer *= 10;
        answer += ary[i];
    }
    
    ary.clear();
    vector<int>().swap(ary);

    return answer;
}



void main()
{
    long long result = 0;
    result = solution(123515);
    cout << result;
}