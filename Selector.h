#ifndef SCHEDULINGCALC_SELECTOR_H
#define SCHEDULINGCALC_SELECTOR_H

#include <iostream>
#include "FCFS.h"
#include "SJF.h"
#include "SRTF.h"

using namespace std;

class Selector {

public:
    static void schedulerChoice(Scheduler &subj) {
        //ask what scheduler to apply to it
        int choice;
        printf("enter selections: \n\t1. FCFS\n\t2. SJF\n\t3. SRTF\n\t4. Priority\n\t5. Round Robin\n");
        cin >> choice;
        switch (choice) {
            case 1: {
                FCFS::FCFSCalc(subj);
                break;
            }
            case 2: {
                SJF::SJFCalc(subj);
                break;
            }
            case 3: {
                SRTF::SRTFCalc(subj);
                break;
            }
//        case 4:
//            PriorityCalc();
//            break;
//        case 5: RRCalc(); break;
            default:
                break;
        }
    }
};

#endif //SCHEDULINGCALC_SELECTOR_H
