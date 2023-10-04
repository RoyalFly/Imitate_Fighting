//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ROBOT_H
#define IMITATE_FIGHTING_ROBOT_H

#include <string>

struct RobotPos {
    float x;
    float y;
};

RobotPos *moveRobot(RobotPos *pos, float dx, float dy);

struct RobotHP {
    int hp;
    int max_hp;
};

typedef enum {
    Engineer,
    Infantry,
    Sentinel,
    Hero
} RobotTypeDef;

typedef enum {
    Red_Team,
    Blue_Team
} CampTypeDef;

struct Robot {
    RobotTypeDef Robot_Type;
    RobotHP HP_State;
    RobotPos Pos_State;
    int Remaining_Ammo; //剩余弹药
    float Self_Aiming_Para;
    int Robot_Level;
    int Robot_Exp;
    float Robot_Speed;
    CampTypeDef Robot_Camp;
    const char *Robot_Number;
};

Robot Red[6];
Robot Blue[6];

#endif//IMITATE_FIGHTING_ROBOT_H
