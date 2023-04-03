#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Node;
class Edge;
class Graph;

class Node {
    public:
    int id;
    std::vector<Edge*> out;

    Node() { id = -1;}

    Node(int id);
};

Node::Node(int id)
{
    this->id = id;
}

class Edge {
    public:
    Node* start;
    Node* end;
    int weight;

    Edge(int weight, Node* startNode, Node* endNode);
    void PrintEdge();
};

Edge::Edge(int weight, Node* startNode, Node* endNode)
{
    this->weight = weight;
    this->start = startNode;
    this->end = endNode;
}

void Edge::PrintEdge()
{
    std::cout << start->id << "--" << weight << "-->" << end->id << std::endl;
}

class Graph {
    public:
    std::unordered_map<int, Node*> nodes;
    std::vector<Edge*> edges;

    Graph(FILE* input);
    void PrintGraph();


    private:
    int nodeID;
    void AddNode();
    void AddEdge(int startNodeID, int endNodeID, int weight);
    void InitGraph(FILE* input);

};

void Graph::AddNode()
{
    Node* node = new Node(nodeID);
    nodes[nodeID] = node;
    nodeID++;
}

Graph::Graph(FILE* input)
{
    int n;
    fscanf(input, "%d", &n);

    nodeID = 1;
    for(int i = 0; i < n; i++)
        AddNode();

    InitGraph(input);
}

void Graph::InitGraph(FILE* input)
{
    int nEdges;
    fscanf(input, "%d", &nEdges);

    for(int i = 0; i < nEdges; i++)
    {
        int start, end, weight;
        fscanf(input, "%d %d %d", &start, &end, &weight);
        AddEdge(start, end, weight);
    }
}

void Graph::AddEdge(int startNodeID, int endNodeID, int weight)
{
    Edge* edge = new Edge(weight, nodes[startNodeID], nodes[endNodeID]);
    nodes[startNodeID]->out.push_back(edge);
    edges.push_back(edge);
}

void Graph::PrintGraph()
{
    for(int i = 1; i < nodeID; i++)
    {
        for(Edge* edge : nodes[i]->out)
        {
            edge->PrintEdge();
        }
    }
}

#endif