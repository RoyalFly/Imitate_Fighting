//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\Architect.h"
#include "..\Inc\robot.h"
#include "random"
#include "..\Inc\main.h"

const float Accuracy_Loss = 0.03;// 每远离目标1m，精准度下降0.03

float dist(RobotPos obj1, RobotPos obj2) {
    return (float) sqrt((double) (obj1.x - obj2.x) * (obj1.x - obj2.x) + (obj1.y - obj2.y) * (obj1.y - obj2.y));
}

extern int tick;
const int Shoot_Interval=3;

void Action_Hero(Robot Present_Hero) {
    static int Last_Shoot_Tick_Red=-5;
    static int Last_Shoot_Tick_Blue=-5;
    if (tick-Last_Shoot_Tick_Red < Shoot_Interval && Present_Hero.Robot_Camp == Red_Team){
        return;
    }
    if (tick-Last_Shoot_Tick_Blue < Shoot_Interval && Present_Hero.Robot_Camp == Blue_Team){
        return;
    }
    if (Present_Hero.Robot_Camp == Red_Team) {
        if (Blue_Tower.HP != 0) {//优先执行对先锋塔吊射
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Blue_Tower.Pos_State) + Red[0].Self_Aiming_Para;
            if (Present_Accuracy < 0.5){ //命中率太低，执行移动操作
                Move_to_Tower(Present_Hero,Blue_Tower);
            } else {
                Attack_Tower(Present_Hero,Blue_Tower);
            }
        } else { //若先锋塔已经被摧毁则索敌
            Robot Aim_Robot=Searching_Enemy(Present_Hero);
            if (Aim_Robot.Robot_Level == -1){ //敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Blue_Base.Pos_State)+Red[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8){
                    Move_to_Base(Present_Hero,Blue_Base);
                }else{
                    Attack_Base(Present_Hero,Blue_Base);
                }
            } else { //找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Aim_Robot.Pos_State)+Red[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8){
                    Move_to_Robot(Present_Hero,Aim_Robot);
                } else {
                    Attack_Robot(Present_Hero,Aim_Robot);
                }
            }
        }
    } else { //蓝方英雄判断，和上面一模一样
        if (Red_Tower.HP != 0) {//优先执行对先锋塔吊射
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Red_Tower.Pos_State) + Blue[0].Self_Aiming_Para;
            if (Present_Accuracy < 0.5){ //命中率太低，执行移动操作
                Move_to_Tower(Present_Hero,Red_Tower);
            } else {
                Attack_Tower(Present_Hero,Red_Tower);
            }
        } else { //若先锋塔已经被摧毁则索敌
            Robot Aim_Robot=Searching_Enemy(Present_Hero);
            if (Aim_Robot.Robot_Level == -1){ //敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Red_Base.Pos_State)+Blue[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8){
                    Move_to_Base(Present_Hero,Blue_Base);
                }else{
                    Attack_Base(Present_Hero,Blue_Base);
                }
            } else { //找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Aim_Robot.Pos_State)+Blue[0].Self_Aiming_Para;
                if (Present_Accuracy < 0.8){
                    Move_to_Robot(Present_Hero,Aim_Robot);
                } else {
                    Attack_Robot(Present_Hero,Aim_Robot);
                }
            }
        }
    }
}
