#ifndef schedulingCalc_SRTF_H
#define schedulingCalc_SRTF_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cstring>

using namespace std;

class SRTF : Scheduler {

private:
    // comparison method for processQueue by burst time
    static bool compare(Process a, Process b) {
        return a.getBurstTime() < b.getBurstTime();
    }

public:
    static void SRTFCalc(Scheduler &subj) {

        // const for CPU cycle units
        const double interval = 1;

        // calc total run time of all processes
        double totalRunTime = 0;
        for (auto procTime : subj.processQueue.processes) {
            totalRunTime += procTime.getBurstTime();
        }

        double remaining = 0;

        double clock = 0;
        while (clock != totalRunTime) {

            // sorting processQueue by burst time.
            sort(subj.processQueue.processes.begin(), subj.processQueue.processes.end(), compare);

            //decrement process burst time in first position by one CPU interval
            remaining = subj.processQueue.processes.front().getBurstRemaining();
            subj.processQueue.processes.front().setBurstRemaining(remaining - interval);
            totalRunTime -= interval;
            if (subj.processQueue.processes.front().getBurstRemaining() == 0) {
                subj.processQueue.processes.front().setCompletionTime(clock);
            }
        }

        // calculating turnaround time by subtracting arrival time from completion time
        for (auto &itr : subj.processQueue.processes) {
            itr.setTurnaroundTime(itr.getCompletionTime() - itr.getArrivalTime());
        }

        // calculate waiting time by subtracting burst time from turnaround time
        for (auto &itr : subj.processQueue.processes) {
            itr.setWaitingTime(itr.getTurnaroundTime() - itr.getBurstTime());
        }

        // display processQueue along with all details
        double total_wt = 0, total_tt = 0;
        // calculate total waiting time and total turn around time
        for (auto &i : subj.processQueue.processes) {
            total_wt += i.getWaitingTime();
            total_tt += i.getTurnaroundTime();
            printf("Process %d : Burst time: %.1f Waiting time: %.1f Turn around time: %.1f\n",
                   i.getPid(), i.getBurstTime(), i.getWaitingTime(), i.getTurnaroundTime());
        }

        cout << "Average waiting time = " << total_wt / subj.processQueue.processes.size();
        cout << "\nAverage turn around time = " << total_tt / subj.processQueue.processes.size();
    }

//    void static SRTFCalc1() {
//
//        int x;
//        struct process p[100];
//        float avg_turnaround_time;
//        float avg_waiting_time;
//        float avg_response_time;
//        float cpu_utilization;
//        int total_turnaround_time = 0;
//        int total_waiting_time = 0;
//        int total_response_time = 0;
//        int total_idle_time = 0;
//        float throughput;
//        int burst_remaining[100];
//        int is_completed[100];
//        memset(is_completed, 0, sizeof(is_completed));
//
//        cout << setprecision(2) << fixed;
//
//        cout << "Enter the number of processes: ";
//        cin >> x;
//
//        for (int i = 0; i < x; i++) {
//            cout << "Enter arrival time of the process " << i + 1 << ": ";
//            cin >> p[i].arrival_time;
//            cout << "Enter burst time of the process " << i + 1 << ": ";
//            cin >> p[i].burst_time;
//            p[i].pid = i + 1;
//            burst_remaining[i] = p[i].burst_time;
//            cout << endl;
//        }
//
//        int current_time = 0;
//        int completed = 0;
//        int prev = 0;
//
//        while (completed != x) {
//            int idx = -1;
//            int mn = 10000000;
//            for (int i = 0; i < x; i++) {
//                if (p[i].arrival_time <= current_time && is_completed[i] == 0) {
//                    if (burst_remaining[i] < mn) {
//                        mn = burst_remaining[i];
//                        idx = i;
//                    }
//                    if (burst_remaining[i] == mn) {
//                        if (p[i].arrival_time < p[idx].arrival_time) {
//                            mn = burst_remaining[i];
//                            idx = i;
//                        }
//                    }
//                }
//            }
//
//            if (idx != -1) {
//                if (burst_remaining[idx] == p[idx].burst_time) {
//                    p[idx].start_time = current_time;
//                    total_idle_time += p[idx].start_time - prev;
//                }
//                burst_remaining[idx] -= 1;
//                current_time++;
//                prev = current_time;
//
//                if (burst_remaining[idx] == 0) {
//                    p[idx].completion_time = current_time;
//                    p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
//                    p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
//                    p[idx].response_time = p[idx].start_time - p[idx].arrival_time;
//
//                    total_turnaround_time += p[idx].turnaround_time;
//                    total_waiting_time += p[idx].waiting_time;
//                    total_response_time += p[idx].response_time;
//
//                    is_completed[idx] = 1;
//                    completed++;
//                }
//            } else {
//                current_time++;
//            }
//        }
//
//        int min_arrival_time = 10000000;
//        int max_completion_time = -1;
//        for (int i = 0; i < x; i++) {
//            min_arrival_time = min(min_arrival_time, p[i].arrival_time);
//            max_completion_time = max(max_completion_time, p[i].completion_time);
//        }
//
//        avg_turnaround_time = (float) total_turnaround_time / x;
//        avg_waiting_time = (float) total_waiting_time / x;
//        avg_response_time = (float) total_response_time / x;
//        cpu_utilization = ((max_completion_time - total_idle_time) / (float) max_completion_time) * 100;
//        throughput = float(x) / (max_completion_time - min_arrival_time);
//
//        cout << endl << endl;
//
//        cout << "Process\t" << "Arrival Time\t" << "Burst Time\t" << "ST\t" << "CT\t" << "TAT\t" << "WT\t" << "RT\t"
//             << "\n"
//             << endl;
//
//        for (int i = 0; i < x; i++) {
//            cout << p[i].pid << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].start_time << "\t"
//                 << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\t"
//                 << p[i].response_time << "\t" << "\n" << endl;
//        }
//        cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
//        cout << "Average Waiting Time = " << avg_waiting_time << endl;
//        cout << "Average Response Time = " << avg_response_time << endl;
//        cout << "CPU Utilization = " << cpu_utilization << "%" << endl;
//        cout << "Throughput = " << throughput << " process/unit time" << endl;
//    }

};

#endif //schedulingCalc_SRTF_H
