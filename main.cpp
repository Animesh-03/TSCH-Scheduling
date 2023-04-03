#include<iostream>
#include<vector>

#include "graph.h"

using namespace std;

int main()
{
    FILE* f = fopen("input.txt", "r");
    Graph* graph = new Graph(f);
    graph->PrintGraph(); 

    return 0;
}