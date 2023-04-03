#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<vector>
#include<stdlib.h>

#include "graph.h"

class TransmissionNode {
    public:
    std::pair<int,int> transmission;
    TransmissionNode* next;

    TransmissionNode(int start, int end);
};

TransmissionNode::TransmissionNode(int start, int end)
{
    this->transmission = {start, end};
    next = NULL;
}

class Schedule {
    public:
    std::vector<std::pair<int,int>> schedule;
    std::vector<std::vector<std::vector<bool>>> check;

    Schedule(int nTimeSlots, int nChannels, int nNodes);
    void CreateSchedule(std::vector<TransmissionNode*> paths);
    void PrintSchedule();

    private:
    int nTimeSlots;
    int nChannels;
    int nNodes;
};

Schedule::Schedule(int nTimeSlots, int nChannels, int nNodes)
{
    this->nTimeSlots = nTimeSlots;
    this->nChannels = nChannels;
    this->nNodes = nNodes;

    for(int i = 0; i < nChannels; i++)
    {
        auto t1 = std::vector<std::vector<bool>>(nTimeSlots, std::vector<bool>(nNodes, false));
        check.push_back(t1);
    }
}

void Schedule::CreateSchedule(std::vector<TransmissionNode*> paths)
{
    std::vector<std::vector<bool>> occupied(nChannels, std::vector<bool>(nTimeSlots, false));

    for(TransmissionNode* path : paths)
    {

        while(path != NULL)
        {
            bool scheduled = false;

            // std::cout << "Scheduling " << "(" << path->transmission.first << "," << path->transmission.second << ")\n";

            for(int i = 0; i < nTimeSlots && !scheduled; i++)
            {
                for(int j = 0; j < nChannels; j++)
                {
                    // Cell is already occupied
                    if(occupied[j][i]) continue;

                    // Cell adds clashes
                    if(check[j][i][path->transmission.first] || check[j][i][path->transmission.second])
                        break;

                    occupied[j][i] = true;

                    for(int l = 0; l < nChannels; l++)
                    {
                        check[l][i][path->transmission.first] = true;
                        check[l][i][path->transmission.second] = true;
                    }

                    std::cout << "(" << path->transmission.first << "," << path->transmission.second << ") at " << j << " " << i << std::endl;


                    scheduled = true;
                    break;
                }
            }

            if(!scheduled) std::cout << "Could not Schedule\n";

            path = path->next;
        }
    }
}
void Schedule::PrintSchedule()
{

}

#endif