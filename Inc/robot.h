//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ROBOT_H
#define IMITATE_FIGHTING_ROBOT_H

#include <string>
#include "TypeDefine.h"
#include "Architect.h"

class Robot{
private:
    RobotTypeDef Robot_Type;
    RobotHP HP_State{};
    RobotPos Pos_State{};
    float Self_Aiming_Para{};
    int Robot_Level{};
    float Robot_Speed{};
    CampTypeDef Robot_Camp;
    const char *Robot_Number{};
    int Damage{};
    int Revive_Time{};

    Robot(RobotTypeDef TYPE,RobotHP hp,RobotPos pos,float Self_Aiming_Para,int Robot_Level,float Robot_Speed,CampTypeDef Camp,const char *Robot_Number,int Damage,int Revive_Time);
public:
    Robot();
    static void Robot_Init();
    RobotPos Move_to(Robot* Present_Robot, RobotPos Des_Pos);
    //void Attack_Tower(Robot *Attacker, Architecture *Aimed_Tower, float Accuracy);
    //void Attack_Base(Robot *Attacker, Architecture *Aimed_Base, float Accuracy);
    Robot *Searching_Enemy(Robot *Present_Robot);
    void Attack_Robot(Robot *Attacker, Robot *Aim, float Accuracy);
    void Attack_Base(Robot *Attacker, float Accuracy);
    void Attack_Tower(Robot *Attacker, float Accuracy);
};

#endif//IMITATE_FIGHTING_ROBOT_H
