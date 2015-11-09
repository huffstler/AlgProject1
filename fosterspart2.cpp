#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <string>
#include <array>
#include <list>

//########################
//						CHANGES					  #
// addEdge - Changed ALOT				  #
// graph constructor: changed a little   #
// added new function BFS				  #
// main changed a little						  #
//########################

using namespace std;

struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode *head;
};

class Graph {
private:
    int V;
    struct AdjList* array;
    list<int> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        array = new AdjList [V];
    }
    
// Creating New Adjacency List Node
    AdjListNode* newAdjListNode (int dest) {
        AdjListNode* newNode = new AdjListNode;
        newNode->dest = dest;
        newNode->next = NULL;
        return newNode;
    }
	
// Adds an Edge to Graph
    void addEdge (int src, int dest) {
        adj[src].push_back(dest);
    }
    
	// where amnt is the amount of objects you're returning, node is the root node and depth is the layer which the algorithm stops at.  ( 1 is direct children, 2 is grandchildren etc, etc)
	//string BFS1(int amnt, string node, int dpth) { 
	//	int amount = amnt;
	//	string root = node;
	//	int depth = dpth;
	//	bool *visited = new bool[V];
		//string highestNode;
// 	'i' will be used to get all adjacent vertices of a vertex
	//	list<int>::iterator i;
		
	//	if (depth == 0) { return root; }
		
//     Mark all the vertices as not visited below
	//	for(int i = 0; i < V; i++)
	//		visited[i] = false;

// 	Create a queue for BFS
	//	list<int> queue;
	//	list<int> depthqueue;
		
	//}
// 	Mark the current node as visited and enqueue it
		//visited[s] = true;				//HAS TO CHANGE USES INT TO FIND NODE
		//queue.push_back(s);		//HAS TO CHANGE USES INT TO PUSH NODE
		
	//	while(!queue.empty()) {
			
// 		Dequeue a vertex from queue and print it
			//s = queue.front();
	//		queue.pop_front();
			
// 		Get all adjacent vertices of the dequeued vertex s
// 		If a adjacent has not been visited, then mark it visited
// 		and enqueue it
	//		for(i = adj[s].begin(); i != adj[s].end(); ++i) {
	//			if(!visited[*i]) {
					
	//				currentDepth++;
	//				visited[*i] = true;
	//				queue.push_back(*i);
					
	//			}
			//}

//			std::string q = std::to_string(s);
			
//			if(currentDepth > max){
//				max = currentDepth;
//				highestNode = q;
//			}
//			currentDepth = 0;
		//}
		//cout << highestNode << "   ";
	
    void BFS2(int s, int maxDepth) {
        int max=0;
		int currentDepth = 0;
        bool *visited = new bool[V];
        string highestNode;
// 	'i' will be used to get all adjacent vertices of a vertex
        list<int>::iterator i;
		
        if (maxDepth == 0) { return; }
		
//     Mark all the vertices as not visited below
        for(int i = 0; i < V; i++)
            visited[i] = false;

// 	Create a queue for BFS
        list<int> queue;
        list<int> depthqueue;
        
// 	Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);
        
        while(!queue.empty()) {
			
// 		Dequeue a vertex from queue and print it
            s = queue.front();
            queue.pop_front();
            
// 		Get all adjacent vertices of the dequeued vertex s
// 		If a adjacent has not been visited, then mark it visited
// 		and enqueue it
            for(i = adj[s].begin(); i != adj[s].end(); ++i) {
                if(!visited[*i]) {
                    
					currentDepth++;
                    visited[*i] = true;
                    queue.push_back(*i);
					
                }
            }

            std::string q = std::to_string(s);
            
            if(currentDepth > max){
                max = currentDepth;
                highestNode = q;
            }
            currentDepth = 0;
        }
        cout << highestNode << "   ";
    }
    
// Prints the graph
    void printGraph() {
        int v;
        for (v = 0; v < V; ++v){
            AdjListNode* pCrawl = array[v].head;
            cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
            while (pCrawl){
                cout<<"-> "<<pCrawl->dest;
                pCrawl = pCrawl->next;
            }
            cout<<endl;
        }
    }
};


int main(){
    
    
}