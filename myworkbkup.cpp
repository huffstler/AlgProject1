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
	//Graph g(1720);
	int hashArray[3449] = { 0 };
	Graph g(1);
	string tempString;
	int count1 = 0;
	int count2 = 0;
	while (getline(cin, tempString, '\n')){ //reads in a line from ideone
		stringstream iss(tempString);
		getline(iss, tempString, ':'); // tempString is currently the parent vert
		string head = tempString;
		count1++;
		while (getline(iss, tempString, ',')){ //go through the line and set tempString to each other vert
			tempString.erase(0, 1);
			
			count2++;
		}
	}
	cout << "Count1: " << count1 << endl;
	cout << "Count2: " << count2 << endl;
	cout << "Total count: " << count1+count2 << endl;
}