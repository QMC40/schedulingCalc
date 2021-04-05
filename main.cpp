#include <iostream>
#include <vector>
#include <string>
#include "Scheduler.h"
#include "Selector.h"
#include "ProcessQueue.h"
#include "Process.h"
//#include "FCFS.h"
//#include "SJF.h"
//#include "SRTF.h"
//#include "PriorityCalc.h"
//#include "RRCalc.h"

using namespace std;

int main() {
    //make a scheduler
    Scheduler test;
    Selector::schedulerChoice(test);

    return 0;
}

