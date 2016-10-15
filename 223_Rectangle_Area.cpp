//223. Rectangle Area
//Find the total area covered by two rectilinear rectangles in a 2D plane.
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//Assume that the total area is never beyond the maximum possible value of int.

#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int s = (C - A) * (D - B) + (G - E) * (H -F);
        if (A >= G || B >= H || E >= C || F >= D) return s;
        return s - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    }
};

int main(){
	Solution testCase;
	int testA, testB, testC, testD, testE, testF, testG, testH;
	cout << "please input the bottom left corner coordinate for rectangle 1" << endl;
	cin >> testA >> testB;
	cout << "please input the upper right corner coordinate for rectangle 1" << endl;
	cin >> testC >> testD;
	cout << "please input the bottom left corner coordinate for rectangle 1" << endl;
	cin >> testE >> testF;
	cout << "please input the upper right corner coordinate for rectangle 1" << endl;
	cin >> testG >> testH;
	int testResult = testCase.computeArea(testA, testB, testC, testD, testE, testF, testG, testH);
	cout << "the result is " << testResult << endl;
}