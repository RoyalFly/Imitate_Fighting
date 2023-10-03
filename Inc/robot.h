//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ROBOT_H
#define IMITATE_FIGHTING_ROBOT_H


struct RobotPos{
    float x;
    float y;
};

RobotPos* moveRobot(RobotPos *pos,float dx,float dy);

struct RobotHP{
    int hp;
    int max_hp;
};

typedef enum{
    Engineer,
    Infantry,
    Sentinel,
    Hero
} RobotTypeDef;

struct Robot{
    RobotTypeDef Robot_Type;
    RobotHP HP_State;
    RobotPos Pos_State;
    int Remaining_Ammo;
    float Self_Aiming_Para;
    int Robot_Level;
    int Robot_Exp;
    float Robot_Speed;
};

Robot Red_r1,Red_r2,Red_r3,Red_r4,Red_r5,Red_r6;
Robot Blue_r1,Blue_r2,Blue_r3,Blue_r4,Blue_r5,Blue_r6;

#endif//IMITATE_FIGHTING_ROBOT_H
