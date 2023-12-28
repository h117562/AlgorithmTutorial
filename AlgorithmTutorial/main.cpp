#include <iostream>

using namespace std;


int PlusN(int x, int n)
{
    return x + n;
}

int Mul2(int x)
{
    return x * 2;
}

int Mul3(int x)
{
    return x * 3;
}

//x를 y로 변환하기 위한 최소 계산 루트를 찾는 함수
int solution(int x, int y, int n, int beforelevel) 
{
    int level = beforelevel;
    int result[3];

    if (x == y)
    {
        return level;
    }

    if (x > y)
    {
        return -1;
    }

    level++;
    result[0] = solution(PlusN(x, n), y, n, level);//합계산 루트
    result[1] = solution(Mul2(x), y, n, level);//2곱 루트
    result[2] = solution(Mul3(x), y, n, level);//3곱 루트
    
    int min = INT_MAX;

    for (int a : result)
    {
        if (min > a && a > 0)
        {
            min = a;
        }
    }

    if (min == INT_MAX)//최소값이 -1 제외하고 없으면
        return -1;
    
    return min;
}

int main()
{
    cout << solution(10, 40, 6, 0);

    return 0;
}