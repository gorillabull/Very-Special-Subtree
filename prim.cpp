
// A C++ program for Prim's Minimum  
// Spanning Tree (MST) algorithm. The program is  
// for adjacency matrix representation of the graph  
//#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>


using namespace std; 
  
// Number of vertices in the graph  
#define V 7
  
// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
int minKey(int key[], bool mstSet[], int size )  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < size; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  
// A utility function to print the  
// constructed MST stored in parent[]  
void printMST(int parent[], vector<vector<int> > graph)  
{  
    int vv = graph.size();

    cout<<"Edge \tWeight\n";  
    for (int i = 1; i <= vv; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
  
// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation  
void primMST(vector<vector<int> > graph )  
{  
    int vv = graph.size();

    // Array to store constructed MST  
    int parent[vv];  
      
    // Key values used to pick minimum weight edge in cut  
    int key[vv];  
      
    // To represent set of vertices not yet included in MST  
    bool mstSet[vv];  
  
    // Initialize all keys as INFINITE  
    for (int i = 0; i < vv; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have V vertices  
    for (int count = 0; count < vv - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey(key, mstSet,vv);  
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  
        for (int v = 0; v < vv; v++)  
  
            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
    // print the constructed MST  
    printMST(parent, graph);  
}  
  


// Driver code 
int main()  
{  
    int g_nodes, g_edges; 
    int gfrom, gto,gweight;

    cin>>g_nodes>>g_edges;

    vector<vector<int> > Graph(g_edges);
    
    for (int i = 0; i < g_edges; i++)
    {
        Graph[i].resize(g_edges);
        for (size_t j = 0; j < g_edges; j++)
        {
            Graph[i][j] =0;
        }
        
        
    }
    for (int i = 0; i < g_edges; i++)
    {
        cin>>gfrom>>gto>>gweight;
        
        Graph[gfrom ][gto]=gweight;
        Graph[gto][gfrom]=gweight;
    }
    
    
    /* Let us create the following graph  
        2 3  
    (0)--(1)--(2)  
    | / \ |  
    6| 8/ \5 |7  
    | / \ |  
    (3)-------(4)  
            9     */
   
  
    // Print the solution 
/*  
int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } }; 
                        
                        */

    primMST(Graph);  
  
    return 0;  
}  
  
// This code is contributed by rathbhupendra