//source: 

/*
This Solution is for Five-in-a-raw chess AI (Artificial Intelligence)
*/

#include <iostream>
#include <vector>

using namespace std;

static const int MAX_SIZE = 25;

#define one    0
#define d_two  5
#define l_two  10
#define d_three 20
#define l_three 40
#define d_four  50
#define l_four  90
#define done_five 200

#define WHITE 2
#define BLACK 1
#define B_NULL 0


class Solution {
public:
//chess board means: 0 means empty, 1 means positive, 2 means negative;
   	bool checkLayout(vector< vector<int> >& chessboard) {
   		//check every line
         int hor = chessboard[0].size();
         int row = chessboard.size();
         
         vector< vector<int> > hor_point = chessboard;
         for (int i = 0; i < hor; ++i)
         {
            for (int j = 0; j < row; ++j)
            {
               hor_point[i][j] = 0;
            }
         }

         vector< vector<int> > row_point = hor_point;
         vector< vector<int> > bias1_point = hor_point;
         vector< vector<int> > bias2_point = hor_point;   

         for (int i = 0; i < chessboard.size(); ++i)
         {
            for (int j = 0; j < chessboard[i].size() ; ++j)
            {
               if ()
               {
                  /* code */
               }
            }
         }  

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
