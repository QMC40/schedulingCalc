#ifndef SCHEDULINGCALC_PROCESSQUEUE_H
#define SCHEDULINGCALC_PROCESSQUEUE_H

#include <iostream>
#include <vector>
#include <string>
#include "Process.h"

using namespace std;

struct ProcessQueue {
    vector<Process> processes;

    explicit ProcessQueue() : processes(processes) {
        dataInput();
    }

    void dataInput() {
        string fields[] = {"arrival time", "CPU burst time", "priority"};
        int procInputs[3];
        int choice;
        cout << "How many processes? ";
        cin >> choice;
        cout << "enter each processes info, omitted selections default to \'0\'\n";
        for (int i = 0; i < choice; i++) {
            printf("----------------------------------------------------------\n");
            printf("Process %d\n", i + 1);
            for (size_t j = 0; j < 3; j++) {
                printf("%s: ", fields[j].c_str());
                cin >> procInputs[j];
            }
            auto *tempProc = new Process(i + 1, procInputs[0], procInputs[1],
                                         procInputs[2]);
            processes.push_back(*tempProc);
        }
    }
};
#endif //SCHEDULINGCALC_PROCESSQUEUE_H
