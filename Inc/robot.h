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
};

#endif//IMITATE_FIGHTING_ROBOT_H
