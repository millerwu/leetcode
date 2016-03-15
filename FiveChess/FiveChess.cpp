//source: 

/*
This Solution is for Five-in-a-raw chess AI (Artificial Intelligence)
*/

#include <iostream>
#include <vector>

using namespace std;

static const int MAX_SIZE = 25;

enum CHESS_POSITIVE_STATUS {
	LOW,
	MIDDLE,
	HIGH,
	END,
};



class Solution {
public:
//chess board means: 0 means empty, 1 means positive, 2 means negative;
   	bool checkLayout(vector< vector<int> >& chessboard) {
   		//check every line
   		for (int i = 0; i < chessboard.size(); ++i)
   		{
   			for (int j = 0; i < chessboard[i].size(); ++j)
   			{
   			}
   		}
   		

   	}
};

int main ()
{
	return 0;
}
