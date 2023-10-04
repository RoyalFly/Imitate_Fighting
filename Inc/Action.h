//
// Created by 98383 on 2023/10/4.
//

#ifndef IMITATE_FIGHTING_ACTION_H
#define IMITATE_FIGHTING_ACTION_H

#include "robot.h"
#include "Architect.h"

float dist(RobotPos obj1, RobotPos obj2);

int max(int x, int y);

RobotPos Move_to(Robot* Present_Robot, RobotPos Des_Pos);

void Attack_Tower(Robot* Attacker, Tower *Aimed_Tower, float Accuracy);

void Attack_Base(Robot* Attacker, Base *Aimed_Base, float Accuracy);

Robot* Searching_Enemy(Robot* Present_Robot);

void Attack_Robot(Robot* Attacker,Robot* Aim,float Accuracy);

#endif//IMITATE_FIGHTING_ACTION_H
