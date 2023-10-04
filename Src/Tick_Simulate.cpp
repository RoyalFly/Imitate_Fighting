//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\Architect.h"
#include "..\Inc\Hero.h"
#include "..\Inc\Sentinel.h"
#include "..\Inc\robot.h"

extern Robot Red[7],Blue[7];

void Tick_Simulate() {
    Action_Hero(&Red[0]);
    Action_Hero(&Blue[0]);
    /*Action_Engineer(Red[1]);
    Action_Engineer(Blue[1]);
    Action_Infantry(Red[2]);
    Action_Infantry(Blue[2]);
    Action_Infantry(Red[3]);
    Action_Infantry(Blue[3]);
    Action_Infantry(Red[4]);
    Action_Infantry(Blue[4]);*/
    Action_Sentinel(&Red[5]);
    Action_Sentinel(&Blue[5]);
}