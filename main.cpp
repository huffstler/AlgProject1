#define WIN32_LEAN_AND_MEAN
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>
#include <fstream>
#include <string>
#include <array>
#include <sstream>
#include <list>

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
			cout << " -> " << edg.getDstNode()->getName();
		}
	}
};

//An object of class graph holds a directed graph
class Graph
{
public:
	vector<Node*> nodeList;//list of verticies
	bool foundCycle;//true if a cycle is found, false otherwise

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
			//	cout << "~~EOL~~" << endl;
		}
	}
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void importData();
bool Problem1(int, string, int);
string Problem2(string);
string Problem3(string, string, string);
Graph G;


int main(){
// This is used for deciding what method to run.	
	int choice;
//Variables used for method 1
	int amount;
	string root; // This is also the only variable needed for Operation 2
	int order;
//Varables used for method 3
	string Ancestor;
	string SpA;
	string SpB;

	importData();
	
	cout << "Which operation would you like to perform? 1, 2, or 3?" << endl;	
	getline(cin, choice);
	cout << choice;
	if (choice == 1) {
		cout << "Please enter the parameters of your choosing. Amount, Root Node, Order. \nAmount:";
		cin >> amount;
		
		cout << "Root Node: ";
		cin >> root;
		
		cout << "Order: ";
		cin >> order;
		
		//cout << "The result for Operation 1 = " << Problem1(amount, root, order) << endl;
	
	}	else if (choice == 2) {
		cout << "Please enter the parameters. Root Node. \nRoot Node:";
		cin >> root;
		cout << root;
		cout << "Problem 2 answer = " << Problem2(root) << endl; 	//Return 3 nodes that are Children of the children of mammal. (Grandchildren of Canidae) 
	
	} else if (choice == 3) {
		//cout << "The result for Operation 3 = " << Problem3(SpA, SpB, Ancestor) << endl;
	} else {
		cout << "Incorrect input. Please try again.";
	}
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
			//cout << "found matching node: " << tempStringP << endl;
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
	//string E = G.findNodeByName("artefact")->adjNodeList[0].orgNode->name;
	//cout << E << endl;
	//G.displayGraph();
	//E.orgNode->getName

	//cout << E << endl;

}

//bool Problem1(int amount, string s, int order) { // we return a list of  all the specific nodes
//	Node* r = G.findNodeByName(s);
//	Node** nArray[] = new Node[ order];
//}

string Problem2(string s) {
	Node* r = G.findNodeByName(s);
	int max = 0;
	int numChildren = 0;
	string highestNode;

	list<int>::iterator i;	//'i' will be used to get all adjacent vertices of a vertex

	G.clearVisited();	//Mark all the vertices as not visited below
	list<Node*> queue;	//Create a queue for BFS

	r->status = VISITED;	//Mark the current node as visited
	queue.push_back(r);		//enqueue the node

	while (!queue.empty()) {

		r = queue.front();	//Dequeue a vertex from queue and print it
		//cout << "About to pop vertex: " << r->name << endl;
		queue.pop_front();
		//cout << "Popped: " << r->name << endl;

		// 		Get all adjacent vertices of the dequeued vertex s
		// 		If a adjacent has not been visited, then mark it visited
		// 		and enqueue it
		//			for (i = adj[s].begin(); i != adj[s].end(); ++i) {
		cout << "There are: " << r->adjNodeList.size() << " vertices incident to " << r->name << endl;
		for (int i = 0; i<r->adjNodeList.size(); i++){
			//cout << "1" << endl;
			if (r->adjNodeList[i].dstNode->status == NOT_VISITED){
				numChildren++;
				//cout << "2" << endl;
				//cout << "We are going to set: " << r->adjNodeList[i].dstNode->name << " to visited" << endl;
				r->adjNodeList[i].dstNode->status = VISITED;
				//cout << "3" << endl;
				queue.push_back(r->adjNodeList[i].dstNode);
			}
		}
		if (numChildren > max){
			max = numChildren;
			highestNode = r->name;
		}
		numChildren = 0;
	}
	return highestNode;
}