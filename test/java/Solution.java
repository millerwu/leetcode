//source:
//author:
//data:

/*

*/

import java.util.*;

public class Solution {

	public static Deque<Solution> mTest = new LinkedList<Solution>();
	public int i = 0;
    
    public static void main(String[] args) {
    	
    	Solution s = new Solution();
        mTest.addLast(s);
        s.i++;
        mTest.addLast(s);
        s.i++;
        mTest.addLast(s);
        for (Solution x : mTest) {   
                System.out.println(x.i);   
        }   
    }
}

    
