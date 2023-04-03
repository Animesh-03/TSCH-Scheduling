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

    vector<TransmissionNode*> t(5);

    TransmissionNode* cur = new TransmissionNode(1,2);
    t[0] = cur;
    cur->next = new TransmissionNode(2,6);

    cur = new TransmissionNode(2,6);
    t[1] = cur;

    cur = new TransmissionNode(3,4);
    t[2] = cur;
    cur->next = new TransmissionNode(4,6);


    cur = new TransmissionNode(4,6);
    t[3] = cur;

    cur = new TransmissionNode(5,6);
    t[4] = cur;

    Schedule* schedule = new Schedule(6, 3, 6);
    schedule->CreateSchedule(t);

    return 0;
}