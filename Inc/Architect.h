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
};

Base Red_Base, Blue_Base;

struct Tower {
    int HP;
    RobotPos Pos_State;
};

Tower Red_Tower, Blue_Tower;

#endif//IMITATE_FIGHTING_ARCHITECT_H
