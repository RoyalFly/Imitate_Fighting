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
    RobotHP HP_State;
    RobotPos Pos_State;
    float Self_Aiming_Para;
    int Robot_Level;
    float Robot_Speed;
    CampTypeDef Robot_Camp;
    const char *Robot_Number;
    int Damage;
    int Revive_Time;

    Robot(RobotTypeDef TYPE,RobotHP hp,RobotPos pos,float Self_Aiming_Para,int Robot_Level,float Robot_Speed,CampTypeDef Camp,const char *Robot_Number,int Damage,int Revive_Time);
public:
    Robot();
    static void Robot_Init();
    void Move_to(Robot* Present_Robot, RobotPos Des_Pos);
    //void Attack_Tower(Robot *Attacker, Architecture *Aimed_Tower, float Accuracy);
    //void Attack_Base(Robot *Attacker, Architecture *Aimed_Base, float Accuracy);
    Robot *Searching_Enemy(Robot *Present_Robot);
    void Attack_Robot(Robot *Attacker, Robot *Aim, float Accuracy);
    void Attack_Base(Robot *Attacker, float Accuracy);
    void Attack_Tower(Robot *Attacker, float Accuracy);
    inline int Get_Reviving_Time();
    inline CampTypeDef Get_Camp();
    inline const char* Get_Name();
    inline void Reviving();
    inline int Get_Level();
    inline RobotPos Get_Pos();
    inline void Revive();
    inline int Get_HP();
    inline float Get_Self_Aiming();
    inline void HP_Loss(int hp_los);
};

inline void Robot::HP_Loss(int hp_los) {
    HP_State.hp=hp_los;
}

inline const char* Robot::Get_Name() {
    return Robot_Number;
}

inline int Robot::Get_Reviving_Time() {
    return Revive_Time;
}

inline void Robot::Reviving() {
    Revive_Time--;
}

inline void Robot::Revive() {
    HP_State.hp=HP_State.max_hp;
}

inline CampTypeDef Robot::Get_Camp(){
    return Robot_Camp;
}

inline int Robot::Get_Level() {
    return Robot_Level;
}

inline RobotPos Robot::Get_Pos() {
    return Pos_State;
}

inline float Robot::Get_Self_Aiming() {
    return Self_Aiming_Para;
}

inline int Robot::Get_HP(){
    return HP_State.hp;
}

#endif//IMITATE_FIGHTING_ROBOT_H
