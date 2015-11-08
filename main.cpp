#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <string>
#include <array>

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
    public:
        Graph(int V) {

            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
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
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
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

Graph mkGraph () {
	
}

int main ( int argc, char *argv[] ) {
	if ( argc != 2 ) {
		cout<<"Too many input parameters. Please only give one text file" << argv[0] << "<filename>\n";
	}
	else {
		ifstream the_file ( argv[1] );
		
		if (!the_file.is_open() ){
			cout<<"Couldn't open the file\n";
		}
		
		else {
			char x;
			
			while ( the_file.get(x))
				cout<<x;
		}
	//file implicitly closed.
	}
}
