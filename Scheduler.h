#ifndef SCHEDULINGCALC_SCHEDULER_H
#define SCHEDULINGCALC_SCHEDULER_H

#include "Process.h"
#include "ProcessQueue.h"

using namespace std;

class Scheduler {

private:
public:

    ProcessQueue processQueue;

    // function to find the waiting time for all processQueue
    void findWaitingTime() {

        // calculating waiting time
        auto lastItr = processQueue.processes.begin();
        auto itr = lastItr + 1;   //first process wait is zero so skipped
        for (; itr != processQueue.processes.end(); itr++, lastItr++) {
            itr->setWaitingTime(lastItr->getBurstTime() + lastItr->getWaitingTime());
        }
    }

    // function to calculate turn around time
    void findTurnAroundTime() {
        // calculating turnaround time by adding
        // burst time + wait time
        for (auto &itr : processQueue.processes) {
            itr.setCompletionTime(itr.getBurstTime() + itr.getWaitingTime());
            itr.setTurnaroundTime(itr.getCompletionTime() - itr.getArrivalTime());
        }
    }

    // function to display results of chosen scheduler
    void displayResults() {
        // display processQueue along with all details
        double total_wt = 0, total_tt = 0;
        // calculate total waiting time and total turn around time
        for (auto &i : processQueue.processes) {
            total_wt += i.getWaitingTime();
            total_tt += i.getTurnaroundTime();
            printf("Process %d : Burst time: %.1f Waiting time: %.1f Turn around time: %.1f\n",
                   i.getPid(), i.getBurstTime(), i.getWaitingTime(), i.getTurnaroundTime());
        }

        cout << "Average waiting time = " << total_wt / processQueue.processes.size();
        cout << "\nAverage turn around time = " << total_tt / processQueue.processes.size();
    }

};

#endif //SCHEDULINGCALC_SCHEDULER_H
