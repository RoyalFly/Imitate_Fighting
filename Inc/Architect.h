//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ARCHITECT_H
#define IMITATE_FIGHTING_ARCHITECT_H
#include "robot.h"

class Architecture{
private:
    int HP;
    RobotPos Pos_State;
    const char* Name;
    CampTypeDef Camp;
    Architecture(int hp,RobotPos pos,const char* name, CampTypeDef camp);
public:
    static void Architect_Init();
    Architecture();
};

void Architect_Init();

#endif//IMITATE_FIGHTING_ARCHITECT_H
