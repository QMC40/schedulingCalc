#ifndef schedulingCalc_SJF_H
#define schedulingCalc_SJF_H

#include<bits/stdc++.h>
#include "Process.h"

using namespace std;

class SJF: public Scheduler {

private:
    // comparison method for processQueue by burst time
    static bool compare (Process a, Process b) {
        return a.getBurstTime() < b.getBurstTime();
    }

public:
    static void SJFCalc(Scheduler &subj) {

        // sorting processQueue by burst time.
        sort(subj.processQueue.processes.begin(), subj.processQueue.processes.end(), compare);

        cout << "*****Shortest Job First*****\n"
                "Order in which processes get executed: ";
        auto itr = subj.processQueue.processes.begin();
        for ( ; itr != subj.processQueue.processes.end() ; itr++) {
            cout << itr->getPid() << " ";
        }
        cout << endl;

        // function to find waiting time of all processQueue
        subj.findWaitingTime();

        // function to find turn around time for all processQueue
        subj.findTurnAroundTime();

        cout << "*****Shortest Job First*****\n";
        subj.displayResults();
    }
};

#endif //schedulingCalc_SJF_H
