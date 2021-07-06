/*Detect cycle in an undirected graph
Given an undirected graph, how to check if there is a cycle in the graph? 
Example, 

Input: n = 4, e = 4 
Output: Yes 
Explanation: 
0 1, 1 2, 2 3, 0 2 

Approach: Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by DFS. 
To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited node then there is a loop and return true.
Algorithm: 

Create the graph using the given number of edges and vertices.
Create a recursive function that that current index or vertex, visited and recursion stack.
Mark the current node as visited and also mark the index in recursion stack.
Find all the vertices which are not visited and are adjacent to the current node. Recursively call the function for those vertices, If the recursive function returns true return true.
If the adjacent vertices are already marked in the recursion stack then return true.
Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true, return true.
Else if for all vertices the function returns false return false.

*/

#include <iostream>
#include <vector>
using namespace std;

bool iscycle(int src, vector<bool> &visited, vector<vector<int>> &adj, int parent)
{
  visited[src] = true;
  for (auto i : adj[src])
  {
    if (i != parent and visited[i] == true)
    {
      return true;
    }
    else
    {
      if (!visited[i] and iscycle(i, visited, adj, src))
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> visited(n, false);
  bool cycle = false;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] and iscycle(i, visited, adj, -1))
    {
      cycle = true;
      if (cycle)
        cout << "cycle is present" << endl;
      else
        cout << "cycle is not present" << endl;
    }
  }
}

/* 

4 3
0 1
1 2
2 0

*/