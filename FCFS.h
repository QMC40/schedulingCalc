#ifndef schedulingCalc_FCFS_H
#define schedulingCalc_FCFS_H

#include <iostream>
#include "ProcessQueue.h"

using namespace std;

class FCFS: public Scheduler {

public:
    //doesn't use priortiy, should use arrival time to arrange order of processing instead of just numbering
    // function to calculate average time
    static void FCFSCalc(Scheduler &subj) {

        // function to find waiting time of all processQueue
        subj.findWaitingTime();

        // function to find turn around time for all processQueue
        subj.findTurnAroundTime();

        // display results
        cout << "*****First Come First Served*****\n";
        subj.displayResults();
  }
};

#endif //schedulingCalc_FCFS_H
