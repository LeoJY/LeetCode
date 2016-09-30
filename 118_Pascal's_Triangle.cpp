//118. Pascal's Triangle
//Given numRows, generate the first numRows of Pascal's triangle.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};

int main()
{
	Solution testcase;
	int num;
	cout << "Please input the number of Rows for the Pascal's Triangle:" << endl;
	cin >> num;
	vector<vector<int>> result = testcase.generate(num);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}