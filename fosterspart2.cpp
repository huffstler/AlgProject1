//
//  main.cpp
//  AlgProject1
//
//  Created by Foster Clark on 11/8/15.
//  Copyright © 2015 Foster Clark. All rights reserved.
//

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
public:
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
    
    void BFS(int s, int maxDepth) {
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

void BFS2(int s, int maxDepth)
    {
        int max=0;
        string highestNode;
        
      //  list<int> maxSP;
        if (maxDepth == 0) { return; }
        int currentDepth = 0;
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
        
        // Create a queue for BFS
        list<int> queue;
        list<int> depthqueue;
        
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);
        
        // 'i' will be used to get all adjacent vertices of a vertex
        list<int>::iterator i;
        
        while(!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
          //  cout << s << " ";
            queue.pop_front();
            
            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it visited
            // and enqueue it
            for(i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if(!visited[*i])
                {
                    currentDepth++;
                  //  cout << currentDepth << "D ";
                    visited[*i] = true;
                    queue.push_back(*i);
                }

            }
            
       //     maxSP.push_back(currentDepth);
       //     m = maxSP.back();
            std::string q = std::to_string(s);
            
            if(currentDepth > max){
                max = currentDepth;
                highestNode = q;
            }
           // cout << highestNode << "";
            currentDepth = 0;
           // cout << maxSP.max_element << " ";
            

            
            
        }
        cout << highestNode << "   ";

        

        
       /* queue.push(firstNode);
        depthQueue.push(0);
        while (!bfsQueue.empty()) {
            f = bfsQueue.front();
            depth = depthQueue.front();
            bfsQueue.pop(), depthQueue.pop();
            for (every node adjacent to f) {
                bfsQueue.push(node), depthQueue.push(depth+1);
            } 
        }*/
    }

int main(){
    //create test graph
    
    //node 0 --> 1,2,
    //node 1 --> 3,4,5
    //node 2 --> 6
    //node 3 --> 7
    
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,6);
    g.addEdge(3,7);
    
   // g.func1(0, 1, 2);
   // g.BFS(0);
    g.BFS(0, 2);
    
    //returns the node that has the highest number of children
    
}