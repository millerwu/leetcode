package MinimumHeightTrees;

/*
For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

Output: [1]
Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

Output: [3, 4]
 */

import java.util.*;

public class MinimumHeightTrees {

    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) return Collections.singletonList(0);
        List<HashSet<Integer>> matrix = new ArrayList<>(n);
        List<Integer> leave = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            matrix.add(new HashSet<>());
        }
        for (int[] edge : edges) {
            matrix.get(edge[0]).add(edge[1]);
            matrix.get(edge[1]).add(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (matrix.get(i).size() == 1)
                leave.add(i);
        }

        while (n > 2) {
            n -= leave.size();
            List<Integer> new_leave = new LinkedList<>();
            for (int i = 0; i < leave.size(); i++) {
                int value = matrix.get(leave.get(i)).iterator().next();
                matrix.get(value).remove(leave.get(i));
                if (matrix.get(value).size() == 1)
                    new_leave.add(value);
            }
            leave = new_leave;
        }
        return leave;
    }

    public static void main(String[] args) {
        int[][] edge1 = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};

    }
}
