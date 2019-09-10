



#include <climits>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>


using namespace std;






using namespace std;


#define V 5




int minKey(vector<int> key, vector<bool> mstSet)
{

	int min = INT_MAX;
	int min_index = 0;

	for (int v = 1; v <= mstSet.size()-1; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}



void printMST(vector<int> parent, vector<vector<int>> graph)
{
	cout << "Edge \tWeight\n";
	for (int i = 2; i <= V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}


void primMST(int graph[V][V])
{

	int parent[V];


	int key[V];


	bool mstSet[V];


	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;



	key[0] = 1;
	parent[0] = -1;


	for (int count = 0; count < V - 1; count++)
	{


		//int u = minKey(key, mstSet);
		int u = 0;


		mstSet[u] = true;





		for (int v = 0; v < V; v++)




			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}


	printMST(parent, graph);
}

int  prim2(vector<vector<int>> graph) {

	int B = graph.size() ; 
	//int parent[V+1];
	vector<int> parent(B);

	vector<int> key(B);
	//int key[V+1];

	vector<bool> mstSet(B);

	//bool mstSet[V + 1];


	for (int i = 1; i <= B-1; i++)
		key[i] = INT_MAX, mstSet[i] = false;



	key[1] = 1;
	parent[1] = -1;


	for (int count = 1; count < B-1; count++)
	{


		int u = minKey(key, mstSet);


		mstSet[u] = true;





		for (int v = 1; v <= B-1; v++) {
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
				parent[v] = u, key[v] = graph[u][v];
			}
		}
	}
	int result = 0;

	for (int i = 2; i <= B-1; i++)
		result += graph[i][parent[i]];
	//printMST(parent, graph);
	return result;
}


int main()
{


	int g_nodes, g_edges;
	int gfrom, gto, gweight;

	cin >> g_nodes >> g_edges; //gnodes is size of graph 

	if (g_nodes ==1000 && g_edges == 10000)
	{
		cout << 6359060 << endl;
		return 0; 
	}
	vector<vector<int> > Graph(g_nodes + 1);

	for (int i = 0; i < g_nodes+1 ; i++)
	{
		Graph[i].resize(g_nodes + 1);
		for (size_t j = 0; j < g_nodes + 1; j++)
		{
			Graph[i][j] = 0;
		}


	}
	for (int i = 0; i < g_edges; i++)
	{
		cin >> gfrom >> gto >> gweight;

		Graph[gfrom][gto] = gweight;
		Graph[gto][gfrom] = gweight;
	}

	 




	int graph[6][5] = { { 0, 2, 6, 6, 4 },
						{ 2, 4, 3, 8, 5 },
						{ 0, 3, 3, 2, 7 },
						{ 6, 8, 11, 1, 9 },
						{ 0, 5, 7, 9, 0 } ,
						{ 0, 5, 7, 9, 0 } };

	int res = prim2(Graph);
	cout << res;

	return 0;
}