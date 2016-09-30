//119. Pascal's Triangle II
//Given an index k, return the kth row of the Pascal's triangle.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        while (rowIndex >= 0)
        {
            if (result.size() < 2)
            {
                result.push_back(1);
            }
            else
            {
                result.push_back(1);
                for (auto i = result.rbegin()+1; i!=result.rend()-1; ++i)
                {
                    *i += * (i+1);
                }
            }
            -- rowIndex;
        }
        return result;
    }
};

int main()
{
	Solution testcase;
	int num;
	cout << "please input the row number: " << endl;
	cin >> num;
	
	vector<int> resultvector = testcase.getRow(num);

	for (int i = 0; i < resultvector.size(); ++i)
	{
		cout << resultvector[i] << '\t';
	}
	cout << endl;

	return 0;
}