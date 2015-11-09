#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>
#include <fstream>
#include <string>
#include <array>
#include <sstream>
#include <unordered_map>
using namespace std;

enum Status {
	NOT_VISITED,
	VISITED
};

//forward declaration
class Node;

//An object of this class represents an edge in the graph.
class Edge
{
public:
	Node *orgNode;//the originating vertex
	Node *dstNode;//the destination vertex

//public:
	Edge(Node *firstNode, Node *secNode)
	{
		orgNode = firstNode;
		dstNode = secNode;
	}

	Node* getDstNode()
	{
		return dstNode;
	}

	Node* getOrgNode()
	{
		return orgNode;
	}
};

//An object of this class holds a vertex of the graph
class Node
{
public:
	string name;
	vector<Edge> adjNodeList;//list of outgoing edges for this vertex
	enum Status status;//used in dfs to mark the node visited

	Node(string id)
	{
		name = id;
		status = NOT_VISITED;
	}

	//do not del the adj nodes here...they will be deleted by graph destructor
	~Node()
	{
		adjNodeList.clear();
	}

	enum Status getStatus()
	{
		return status;
	}

	void setStatus(enum Status st)
	{
		status = st;
	}

	string getName()
	{
		return name;
	}

	void addAdjNode(Node *adj)
	{
		//create an edge with 'this' as the originating node and adj as the destination node
		Edge newEdge(this, adj);
		adjNodeList.push_back(newEdge);
	}

	vector<Edge>& getAdjNodeList()
	{
		return adjNodeList;
	}

	//displays all adjacent verticies of this vertex
	void displayList()
	{
		//string edgeOp = " -> ";
		cout << name;
		for (int i = 0; i < adjNodeList.size(); i++)
		{
			Edge edg = adjNodeList[i];
			cout <<" -> "<< edg.getDstNode()->getName();
		}

	}
};

//An object of class graph holds a directed graph
class Graph
{
public:
	vector<Node*> nodeList;//list of verticies
	bool foundCycle;//true if a cycle is found, false otherwise
	int desiredCycSize;

	void clearVisited()
	{
		for (int i = 0; i < nodeList.size() && !foundCycle; i++)
		{
			nodeList[i]->setStatus(NOT_VISITED);
		}
	}

	void addNewNode(Node *nNode)
	{
		nodeList.push_back(nNode);
	}

	Node* findNodeByName(string name)
	{
		for (int i = 0; i < nodeList.size(); i++)
		{
			if (nodeList[i]->getName() == name)
				return nodeList[i];
		}
		return NULL;
	}

	Graph()
	{
		foundCycle = false;
	}

	~Graph()
	{
		//free mem allocated to verticies
		for (int i = 0; i < nodeList.size(); i++)
			delete nodeList[i];
		nodeList.clear();
	}


	void displayGraph()
	{
		for (int i = 0; i < nodeList.size(); i++)
		{
			nodeList[i]->displayList();
			cout <<"~~EOL~~"<< endl;
		}
	}

	/*void readFlightSchedules() {

	unsigned numOfCities, numOfFlights, cycSize;
	//read in number of cities(TODO:in current implementation..not reqd), number of edges and the desired tour size
	cin >> numOfCities >> numOfFlights >> cycSize;

	while (numOfFlights--)
	{
	string fromCity, toCity;
	unsigned cost;

	cin >> fromCity >> toCity >> cost;
	//find if a vertex for the city already exists, if so get that
	Node *u = findNodeByName(fromCity);
	if (u == NULL)
	{
	u = new Node(fromCity);
	addNewNode(u);
	}

	//find if a vertex for the city already exists, if so get that
	Node *v = findNodeByName(toCity);
	if (v == NULL)
	{
	v = new Node(toCity);
	addNewNode(v);
	}

	u->addAdjNode(v, cost);
	}
	desiredCycSize = cycSize;
	}*/

};












//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void importData();
Graph G;


int main(){
	importData();
	system("pause");
	return 0;
}



void importData(){

	string tempStringP;
	string tempStringC;
	int count = 0;
	//unordered_map<string, int> m;
	while (getline(cin, tempStringP, '\n')){ //reads in a line from ideone
		for (int i = 0; tempStringP[i] != '\0'; i++){//lowercase everything
			tempStringP[i] = tolower(tempStringP[i]);
		}
		stringstream iss(tempStringP);
		getline(iss, tempStringP, ':'); // tempString is currently the parent vert
		Node* PNode = G.findNodeByName(tempStringP);
		if (PNode){
		//	cout << "found matching node: " << tempStringP << endl;
		}
		else{
			PNode = new Node(tempStringP);
			G.addNewNode(PNode);
			//cout << "added Node: " << tempStringP << " as a parent node" << endl;
			//cout << tempString << endl;
			count++;
		}
		while (getline(iss, tempStringC, ',')){ //go through the line and set tempString to each other vert
			tempStringC.erase(0, 1);
			//check if this string is already currently a vert
			if (Node* N = G.findNodeByName(tempStringC)){
				//cout << "found matching node: " << tempStringC << endl;
				PNode->addAdjNode(N);
			}
			else{
				Node *CNode = new Node(tempStringC);
				G.addNewNode(CNode);
				PNode->addAdjNode(CNode);
				//cout << "created/added: " << tempStringC << " as a child node of: " << tempStringP << endl;
				count++;
			}
			//if it isnt a vert we create it
			//

			//	cout << tempString << endl;
		}
	}
	cout << count << endl;
	//G.findNodeByName("artefact")->displayList();
	string E = G.findNodeByName("artefact")->adjNodeList[0].orgNode->name;
			cout << E << endl;
			G.displayGraph();
	//E.orgNode->getName

	//cout << E << endl;

}