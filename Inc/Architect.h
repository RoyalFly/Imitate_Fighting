//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ARCHITECT_H
#define IMITATE_FIGHTING_ARCHITECT_H
#include "robot.h"

struct Base {
    int HP;
    bool Armour;
    RobotPos Pos_State;
    const char* Name;
    CampTypeDef Camp;
};

struct Tower {
    int HP;
    RobotPos Pos_State;
    const char* Name;
};

void Architect_Init();

#endif//IMITATE_FIGHTING_ARCHITECT_H
