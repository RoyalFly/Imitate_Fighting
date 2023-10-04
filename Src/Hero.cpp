//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\Architect.h"
#include "Action.cpp"

const float Accuracy_Loss = 0.03;// 每远离目标1m，精准度下降0.03

extern int tick;
const int Shoot_Interval = 3;

static void Action_Hero(Robot* Present_Hero) {
    static int Last_Shoot_Tick_Red = -5;
    static int Last_Shoot_Tick_Blue = -5;
    if (tick - Last_Shoot_Tick_Red < Shoot_Interval && Present_Hero->Robot_Camp == Red_Team) { //枪口冷却
        return;
    }
    if (tick - Last_Shoot_Tick_Blue < Shoot_Interval && Present_Hero->Robot_Camp == Blue_Team) {
        return;
    }
    if (Present_Hero->Revive_Time!=0){ //等待复活
        Present_Hero->Revive_Time--;
        return;
    }
    if (Present_Hero->Robot_Camp == Red_Team) {
        if (Blue_Tower.HP != 0) {//优先执行对先锋塔吊射
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Pos_State, Blue_Tower.Pos_State) + Red[0].Self_Aiming_Para;
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Hero->Pos_State=Move_to(Present_Hero, Blue_Tower.Pos_State);
            } else {
                Attack_Tower(Present_Hero, &Blue_Tower, Present_Accuracy);
                Last_Shoot_Tick_Red=tick;
            }
        } else {//若先锋塔已经被摧毁则索敌
            Robot* Aim_Robot = Searching_Enemy(Present_Hero); // Searching_Enemy需要返回一个机器人类型的指针
            if (Aim_Robot->Robot_Level == -1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Pos_State, Blue_Base.Pos_State) + Red[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Pos_State=Move_to(Present_Hero, Blue_Base.Pos_State);
                } else {
                    Attack_Base(Present_Hero, &Blue_Base, Present_Accuracy);
                    Last_Shoot_Tick_Red=tick;
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Pos_State, Aim_Robot->Pos_State) + Red[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Pos_State=Move_to(Present_Hero, Aim_Robot->Pos_State);
                } else {
                    Attack_Robot(Present_Hero, Aim_Robot, Present_Accuracy);
                    Last_Shoot_Tick_Red=tick;
                }
            }
        }
    } else {                    //蓝方英雄判断，和上面一模一样
        if (Red_Tower.HP != 0) {//优先执行对先锋塔吊射
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Pos_State, Red_Tower.Pos_State) + Blue[0].Self_Aiming_Para;
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Hero->Pos_State=Move_to(Present_Hero, Red_Tower.Pos_State);
            } else {
                Attack_Tower(Present_Hero, &Red_Tower, Present_Accuracy);
                Last_Shoot_Tick_Blue=tick;
            }
        } else {//若先锋塔已经被摧毁则索敌
            Robot* Aim_Robot = Searching_Enemy(Present_Hero);
            if (Aim_Robot->Robot_Level == -1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Pos_State, Red_Base.Pos_State) + Blue[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Pos_State=Move_to(Present_Hero, Blue_Base.Pos_State);
                } else {
                    Attack_Base(Present_Hero, &Blue_Base, Present_Accuracy);
                    Last_Shoot_Tick_Blue=tick;
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Pos_State, Aim_Robot->Pos_State) + Blue[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Pos_State=Move_to(Present_Hero, Aim_Robot->Pos_State);
                } else {
                    Attack_Robot(Present_Hero, Aim_Robot, Present_Accuracy);
                    Last_Shoot_Tick_Blue=tick;
                }
            }
        }
    }
}
