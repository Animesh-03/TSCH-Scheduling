#include<iostream>
#include<vector>

#include "graph.h"
#include "schedule.h"

using namespace std;

int main()
{
    FILE* f = fopen("input.txt", "r");
    Graph* graph = new Graph(f);
    // graph->PrintGraph(); 

    int nTransmissions = 0;
    fscanf(f,"%d", &nTransmissions);

    vector<TransmissionNode*> t(nTransmissions);

    for(int i = 0; i < nTransmissions; i++)
    {
        int nNodes;
        fscanf(f,"%d", &nNodes);
        vector<int> nodes(nNodes);
        for(int j = 0; j < nNodes; j++)
        {
            fscanf(f,"%d", &nodes[j]);
        }

        TransmissionNode* cur = new TransmissionNode(nodes[0], nodes[1]);
        t[i] = cur;
        for(int j = 1; j < nNodes - 1; j++)
        {
            printf("New node for: %d %d\n", nodes[j], nodes[j+1]);
            cur->next = new TransmissionNode(nodes[j], nodes[j + 1]);
            cur = cur->next;
        }
    }

    // TransmissionNode* cur = new TransmissionNode(1,2);
    // t[0] = cur;
    // cur->next = new TransmissionNode(2,6);

    // cur = new TransmissionNode(2,6);
    // t[1] = cur;

    // cur = new TransmissionNode(3,4);
    // t[2] = cur;
    // cur->next = new TransmissionNode(4,6);


    // cur = new TransmissionNode(4,6);
    // t[3] = cur;

    // cur = new TransmissionNode(5,6);
    // t[4] = cur;

    Schedule* schedule = new Schedule(6, 3, 6);
    schedule->CreateSchedule(t);

    return 0;
}