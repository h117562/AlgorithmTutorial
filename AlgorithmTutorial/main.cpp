#include <iostream>
#include <vector>

using namespace std;

void solution(vector<vector<int>>& answer, vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    answer = arr1;

    if (arr1.size() != arr2.size() && arr1[0].size() != arr2[0].size())//두 행렬 사이즈가 다를 때
        return;

    
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1[0].size(); j++)
        {
            answer[i][j] = answer[i][j] + arr2[i][j];
        }
    }

    return;
}

void main()
{
    vector<vector<int>> arr1 = { {1,2,3},{1,2,3} };
    vector<vector<int>> arr2 = { {1,2,3},{1,2,3} };
    vector<vector<int>> sum;

    solution(sum, arr1, arr2);


    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[0].size(); j++)
        {
            cout << sum[i][j] << ", ";
        }
        cout << endl;
    }
}