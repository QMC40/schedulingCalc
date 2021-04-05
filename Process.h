#ifndef SCHEDULINGCALC_PROCESS_H
#define SCHEDULINGCALC_PROCESS_H

#include "Scheduler.h"

struct Process {

    int pid;
    int priority;
    double arrival_time;
    double burst_time;
    double burst_remaining;
    double start_time = 0;
    double completion_time = 0;
    double turnaround_time = 0;
    double waiting_time = 0;
    double response_time = 0;

    explicit Process(int pid, double arrival_time = 0, double burstTime = 0,
                     int priority = 0) : pid(pid),arrival_time(arrival_time),
                     burst_time(burstTime),priority(priority) { burst_remaining = burstTime; }


    int getPid() const {
        return pid;
    }

    void setPid(int id) {
        pid = id;
    }

    double getArrivalTime() const {
        return arrival_time;
    }

    void setArrivalTime(double arrivalTime) {
        arrival_time = arrivalTime;
    }

    double getBurstTime() const {
        return burst_time;
    }

    void setBurstTime(double burstTime) {
        burst_time = burstTime;
    }
    
    double getBurstRemaining() const {
        return burst_remaining;
    }

    void setBurstRemaining(double burstRemaining) {
        burst_remaining = burstRemaining;
    }

    double getStartTime() const {
        return start_time;
    }

    void setStartTime(double startTime) {
        start_time = startTime;
    }

    double getCompletionTime() const {
        return completion_time;
    }

    void setCompletionTime(double completionTime) {
        completion_time = completionTime;
    }

    double getTurnaroundTime() const {
        return turnaround_time;
    }

    void setTurnaroundTime(double turnaroundTime) {
        turnaround_time = turnaroundTime;
    }

    double getWaitingTime() const {
        return waiting_time;
    }

    void setWaitingTime(double waitingTime) {
        waiting_time = waitingTime;
    }

    double getResponseTime() const {
        return response_time;
    }

    void setResponseTime(double responseTime) {
        response_time = responseTime;
    }

    int getPriority() const {
        return priority;
    }

    void setPriority(int pri) {
        priority = pri;
    }
};

#endif //SCHEDULINGCALC_PROCESS_H
