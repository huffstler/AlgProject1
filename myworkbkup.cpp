#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>
#include <fstream>
#include <string>
#include <array>
#include <sstream>
using namespace std;

struct AdjListNode{
	int dest;
	string name;
	struct AdjListNode* next;
};
struct AdjList{
	struct AdjListNode *head;
	string title;
};

class Graph
{
private:
	int V;
	struct AdjList* array;
public:
	Graph(int V)
	{
		this->V = V;
		array = new AdjList[V];
		for (int i = 0; i < V; ++i)
			array[i].head = NULL;
	}
	/*
	 * Creating New Adjacency List Node
	 */
	AdjListNode* newAdjListNode(int dest)
	{
		AdjListNode* newNode = new AdjListNode;
		newNode->dest = dest;
		newNode->next = NULL;
		return newNode;
	}
	/*
	 * Adding Edge to Graph
	 */
	void addEdge(int src, int dest, string name)
	{
		AdjListNode* newNode = newAdjListNode(dest);
		newNode->next = array[src].head;
		array[src].head = newNode;
		newNode = newAdjListNode(src);
		newNode->next = array[dest].head;
		newNode->name = name;
		array[dest].head = newNode;
	}
	/*
	 * Print the graph
	 */
	void printGraph()
	{
		int v;
		for (v = 0; v < V; ++v)
		{
			AdjListNode* pCrawl = array[v].head;
			cout << "\n Adjacency list of vertex " << v << "\n head ";
			while (pCrawl)
			{
				cout << "-> " << pCrawl->dest;
				pCrawl = pCrawl->next;
			}
			cout << endl;
		}
	}
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void importData();
string FileName = "C://";

int main(){
	importData();
	system("pause");
	return 0;
}

void importData(){
	
	/* Importing data kind of like this:

		
   headCnt _ _ _ _
		/ |_|_|_|_|
		| |_|_|_|_|
		| |_|_|_|_|
		\ |_|_|_|_|
		  \_______/	
		   tailCnt
		*/
	//Graph g(1720);
	int hashArray[3449] = { 0 };
	Graph g(1720);
	string headString;
	string tailString
	int headCnt = 0;
	int tailCnt = 0;
	while (getline(cin, headString, '\n')){ //reads in a line from ideone
		stringstream iss(headString);
		getline(iss, headString, ':'); // headString is currently the parent vert
		string head = headString;
		headCnt++; //Number of rows
		tailString = headString;
		while (getline(iss, tailString, ',')){ //go through the line and set tailString to each other vert
			tailString.erase(0, 1);
			g.addEdge(headCnt, tailCnt, tailString);
			cout << "Edge: " << headCnt << " " << tailCnt << " Added. It connects" << tempString << " to ."<< endl; 
			tailCnt++; //Number of columns (Sort of)
		}
	}
	cout << "Count1: " << headCnt << endl;
	cout << "Count2: " << tailCnt << endl;
	cout << "Total count: " << headCnt+tailCnt << endl;
}