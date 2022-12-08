#include <iostream>
#include<list>

#define MAXV 10
using namespace std;


struct Graph{
    int nvertices;
    int nedges;
    int degree[MAXV+1];
    list<int> *adjlist;

};

void init_graph(Graph *g){
    g->nvertices = 0;
    g->nedges = 0;
    g->adjlist = new list<int> [MAXV];

}

void print(Graph *g){
    for(int i=0;i<MAXV;i++){
        cout<<i<<"-->";
        for(int it:g->adjlist[i]){
            cout<<it<<" ";
        }
        cout<<endl;
        }
    cout<<endl;
    }

void insert_edge(Graph *g, int from, int to){
    g->adjlist[from].push_back(to);
}

int main(){
    struct Graph *g = new Graph; 
    init_graph(g);
    insert_edge(g, 1,2);
    insert_edge(g, 1,3);
    print(g);
}