#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct graphVertex;

struct graphArc {
    graphVertex *destination;
    graphArc *nextArc;
};

struct graphVertex {
    graphVertex *nextVertex;
    char data;
    bool processed;
    bool inStack;
    bool enqueued;
    graphArc *firstArc;
};

struct graphHead {
    int count;
    graphVertex *first;
};

class Graph {
    graphHead *graph;
    public:
    Graph() {
        graph = new graphHead;
        graph->count = 0;
        graph->first = NULL;
    }
    void insertVertex(char dataIn) {
        graphVertex *newVertex = new graphVertex;
        newVertex->data = dataIn;
        newVertex->processed = false;
        newVertex->inStack = false;
        newVertex->enqueued = false;
        newVertex->nextVertex = NULL;
        if (graph->count==0) {
            graph->first = newVertex;
        }
        else {
            newVertex->nextVertex = graph->first;
            graph->first = newVertex;
        }
        graph->count++;
    }
    int insertArc(char fromKey, char toKey) {
        graphArc *newArc = new graphArc;
        graphVertex *fromVertex=NULL, *toVertex=NULL, *tmp=graph->first;
        while(tmp!=NULL) {
            if (tmp->data == fromKey) fromVertex = tmp;
            tmp=tmp->nextVertex;
        }
        tmp = graph->first;
        while(tmp!=NULL) {
            if (tmp->data == toKey) toVertex = tmp;
            tmp=tmp->nextVertex;
        }
        // cout<<fromVertex<<" "<<toVertex<<endl;
        if(fromVertex == NULL) return -2;
        if(toVertex == NULL) return -3;
        newArc->destination = toVertex;
        if(fromVertex->firstArc == NULL) {
            fromVertex->firstArc = newArc;
            newArc->nextArc = NULL;
            return 1;
        }
        newArc->nextArc = fromVertex->firstArc;
        fromVertex->firstArc = newArc;
        return 1;
    }
    void breadthFirst() {
        queue<graphVertex*> q;
        if (graph->count == 0) return;
        graphVertex *tmp = graph->first;
        graphArc *tmp2;
        while(tmp!=NULL) {
            tmp->processed = false;
            tmp->inStack = false;
            tmp->enqueued = false;
            tmp = tmp->nextVertex;
        }
        tmp = graph->first;
        while(tmp!=NULL) {
            if (tmp->processed == false) {
                if (tmp->enqueued == false) {
                    q.push(tmp);
                    tmp->enqueued = true;
                }
                while(!q.empty()) {
                    cout<<q.front()->data<<" ";
                    q.front()->processed = true;
                    tmp2 = q.front()->firstArc;
                    while (tmp2 != NULL) {
                        if (tmp2->destination->enqueued == false || tmp2->destination->processed == false) {
                            q.push(tmp2->destination);
                            tmp2->destination->enqueued = true;
                        }
                        tmp2 = tmp2->nextArc;
                    }
                    q.pop();
                }
            }
            tmp = tmp->nextVertex;
        }
    }
    void depthFirst() {
        stack<graphVertex*> s;
        if (graph->count==0) return;
        graphVertex *tmp = graph->first;
        graphArc *tmp2;
        while(tmp!=NULL) {
            tmp->processed = false;
            tmp->inStack = false;
            tmp->enqueued = false;
            tmp = tmp->nextVertex;
        }
        tmp = graph->first;
        while (tmp!=NULL) {
            if (tmp->processed == false) {
                if (tmp->inStack == false) {
                    s.push(tmp);
                    tmp->processed = true;
                    tmp->inStack = true;
                }
                while(!s.empty()) {
                    tmp = s.top(); s.pop();
                    cout<<tmp->data<<" ";
                    tmp->processed = true;
                    tmp2 = tmp->firstArc;
                    while (tmp2!=NULL) {
                        if (tmp2->destination->inStack == false) {
                            s.push(tmp2->destination);
                            tmp2->destination->inStack = true;
                        }
                        tmp2 = tmp2->nextArc;
                    }
                }
            }
            tmp = tmp->nextVertex;
        }
    }
    void displayGraph() {
        graphVertex *vertex = graph->first;
        graphArc *arc;
        while(vertex != NULL) {
            cout<<vertex->data<<" -> ";
            arc = vertex->firstArc;
            while (arc != NULL) {
                cout<<arc->destination->data<<" -> ";
                arc=arc->nextArc;
            }
            cout<<endl;
            vertex = vertex->nextVertex;
        }
    }
}; 

int main() {
    int op; Graph g; char dummy,dummy2;
    do {
        cout<<"Enter an option (1. Insert Vertex 2. Insert Arc 3. BFS 4. DFS 5. Display graph): ";cin>>op;
        switch(op) {
            case 1:
            cout<<"Enter data: ";cin>>dummy;
            g.insertVertex(dummy);break;
            case 2:
            cout<<"Enter from: ";cin>>dummy;
            cout<<"Enter to: ";cin>>dummy2;
            cout<<g.insertArc(dummy,dummy2)<<endl;break;
            case 3:
            g.breadthFirst();cout<<endl;break;
            case 4:
            g.depthFirst();cout<<endl;break;
            case 5:
            g.displayGraph();break;
            default:
            cout<<"Invalid option! Please try again."<<endl;
        }
    } while(op!=0);
    return 0;
}