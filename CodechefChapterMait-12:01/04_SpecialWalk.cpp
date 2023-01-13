// Include header file
#include <iostream>

using namespace std;
/*
  C++ Program
  Find nodes which are not part of any cycle in a directed graph
*/
// Define edge of graph node
class AjlistNode
{
	public:
	// Vertices id
	int id;
	AjlistNode *next;
	AjlistNode(int id)
	{
		this->id = id;
		this->next = NULL;
	}
};
// Define node of graph
class GraphNode
{
	public:
	// node key value
	int data;
	AjlistNode *edge;
	GraphNode()
	{
		this->data = 0;
		this->edge = NULL;
	}
	GraphNode(int data)
	{
		this->data = data;
		this->edge = NULL;
	}
};
// Define structure of graph
class MyGraph
{
	public:
	// Number of graph nodes
	int size;
	GraphNode *node;
	MyGraph(int size)
	{
		if (size < 0)
		{
			cout << "\n Invalid size of nodes " << size << " \n";
		}
		else
		{
			this->size = size;
			this->node = new GraphNode[this->size];
			int i = 0;
			//   Set graph node level and e
			i = 0;
			while (i < this->size)
			{
				this->node[i].data = i;
				this->node[i].edge = NULL;
				i++;
			}
		}
	}
	//This function are connect nodes with one edge 
	void connectEdge(int a, int b)
	{
		if (this->size <= 0)
		{
			cout << "\n Graph have no nodes \n";
			return;
		}
		// Create Adjacency node
		AjlistNode *newEdge = new AjlistNode(b);
		if (newEdge != NULL)
		{
			// Get first edge of [i] node
			AjlistNode *edge = this->node[a].edge;
			if (edge == NULL)
			{
				// Whe no edge of graph node [i] then
				// Add a first edge of a [i] node
				this->node[a].edge = newEdge;
			}
			else
			{
				//Find last location to add new edge
				while (edge->next != NULL)
				{
					edge = edge->next;
				}
				// Add edge at last position
				edge->next = newEdge;
			}
		}
		else
		{
			cout << "\nMemory overflow, when connect a new edge from ( " << a << " to " << b << " ) nodes. \n";
		}
	}
	// This function is add new edge
	void addEdge(int a, int b)
	{
		if (this->size > 0 && a < this->size && b < this->size)
		{
			// connect edge
			// a---->b
			this->connectEdge(a, b);
		}
		else
		{
			//not valid Vertices
			cout << "Invalid Node Vertices " << a << " " << b;
		}
	}
	//Display Adjacency list of vertex
	void printGraph()
	{
		if (this->size > 0)
		{
			AjlistNode *temp = NULL;
			// Loop controlling variable
			int i = 0;
			for (i = 0; i < this->size; i++)
			{
				cout << "\n Adjacency list of vertex " << i << " :";
				// Get first edge of [i] node
				temp = this->node[i].edge;
				while (temp != NULL)
				{
					//temp->id is graph node vertices
					//in this case temp->id is same as 
					//node[temp->id].data
					cout << "  " << this->node[temp->id].data;
					temp = temp->next;
				}
			}
		}
		else
		{
			cout << "Empty Graph Node";
		}
	}
	void resetDefault(bool visit[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			visit[i] = false;
		}
	}
	// This function are detect loop in given source code
	bool isCyclic(bool visit[], int source, int current)
	{
		if (source == current && visit[current] == true)
		{
			// When loop exist
			return true;
		}
		else
		{
			if (visit[current] == true)
			{
				// When intermediate node contains loop
				// back to previous process
				return false;
			}
		}
		AjlistNode *temp = this->node[current].edge;
		// Active the visiting node status
		visit[current] = true;
		// iterating the nodes edges
		while (temp != NULL)
		{
			if (this->isCyclic(visit, source, temp->id) == true)
			{
				// When source node contains cycle
				return true;
			}
			// Visit to next edge
			temp = temp->next;
		}
		// Deactivate the current visiting node status
		visit[current] = false;
		return false;
	}
	void nonCyclicNode()
	{
		if (this->size > 0)
		{
			bool visit[this->size];
			bool cycle[this->size];
			// Set that initial have no cyclic node
			this->resetDefault(cycle, this->size);
			for (int i = 0; i < this->size; ++i)
			{
				if (cycle[i] == false)
				{
					this->resetDefault(visit, this->size);
					// Check that cycle
					if (this->isCyclic(visit, i, i) == true)
					{
						// When i contain cycle 
						// Then collect the cycle node 
						for (int j = 0; j < this->size; ++j)
						{
							if (visit[j] == true)
							{
								// contain cycle
								cycle[j] = true;
							}
						}
					}
				}
			}
			// result counter
			int count = 0;
			cout << "\n Result : ";
			// Print resultant node
			for (int j = 0; j < this->size; ++j)
			{
				if (cycle[j] == false)
				{
					// Count the number of resultant nodes
					count++;
					cout << " " << j;
				}
			}
			if (count == 0)
			{
				// In case no result
				cout << "\n None \n";
			}
		}
	}
};
int main()
{
	// 8 is number of nodes
	MyGraph *graph = new MyGraph(5);
	//Connected two node with Edges
	graph->addEdge(0, 1);
	graph->addEdge(1, 2);
	graph->addEdge(2, 3);
	graph->addEdge(3, 1);
	graph->addEdge(3, 4);
	graph->printGraph();
	graph->nonCyclicNode();
	return 0;
}