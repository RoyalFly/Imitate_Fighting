//
// Created by 98383 on 2023/10/3.
//
//todo:好像class的指针出现了问题，索敌和造成伤害的返回值都出了挺大的问题，需要修改
#include "..\Inc\Architect.h"
#include "Action.cpp"

const float Accuracy_Loss = 0.03;// 每远离目标1m，精准度下降0.03

extern int tick;
const int Shoot_Interval = 3;

void Action_Hero(Robot* Present_Hero) {
    static int Last_Shoot_Tick_Red = -5;
    static int Last_Shoot_Tick_Blue = -5;
    if (tick - Last_Shoot_Tick_Red < Shoot_Interval && Present_Hero->Get_Camp() == Red_Team) { //枪口冷却
        return;
    }
    if (tick - Last_Shoot_Tick_Blue < Shoot_Interval && Present_Hero->Get_Camp() == Blue_Team) {
        return;
    }
    if (Present_Hero->Get_Reviving_Time()!=0){ //等待复活
        Present_Hero->Reviving();
        if (Present_Hero->Get_Reviving_Time() == 0){
            Present_Hero->Revive();
        }
        return;
    }
    if (Present_Hero->Get_Camp() == Red_Team) {
        if (Blue_Tower.Get_HP() != 0) {//优先执行对先锋塔吊
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Get_Pos(), Blue_Tower.Get_Pos()) + Red[0].Get_Self_Aiming();
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Hero->Move_to(Present_Hero, Blue_Tower.Get_Pos());
            } else {
                Present_Hero->Attack_Tower(Present_Hero, Present_Accuracy);
                Last_Shoot_Tick_Red=tick;
            }
        } else {//若先锋塔已经被摧毁则索敌
            Robot* Aim_Robot = Present_Hero->Searching_Enemy(Present_Hero); // Searching_Enemy需要返回一个机器人类型的指针
            if (Aim_Robot->Get_Level() != 1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Get_Pos(), Blue_Base.Get_Pos()) + Red[0].Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Move_to(Present_Hero, Blue_Base.Get_Pos());
                } else {
                    Present_Hero->Attack_Base(Present_Hero, Present_Accuracy);
                    Last_Shoot_Tick_Red=tick;
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Get_Pos(), Aim_Robot->Get_Pos()) + Red[0].Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Move_to(Present_Hero, Aim_Robot->Get_Pos());
                } else {
                    Present_Hero->Attack_Robot(Present_Hero, Aim_Robot, Present_Accuracy);
                    Last_Shoot_Tick_Red=tick;
                }
            }
        }
    } else {                    //蓝方英雄判断，和上面一模一样
        if (Red_Tower.Get_HP() != 0) {//优先执行对先锋塔吊射
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Get_Pos(), Red_Tower.Get_Pos()) + Blue[0].Get_Self_Aiming();
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Hero->Move_to(Present_Hero, Red_Tower.Get_Pos());
            } else {
                Present_Hero->Attack_Tower(Present_Hero, Present_Accuracy);
                Last_Shoot_Tick_Blue=tick;
            }
        } else {//若先锋塔已经被摧毁则索敌
            Robot* Aim_Robot = Present_Hero->Searching_Enemy(Present_Hero);
            if (Aim_Robot->Get_Level() != 1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Get_Pos(), Red_Base.Get_Pos()) + Blue[0].Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Move_to(Present_Hero, Blue_Base.Get_Pos());
                } else {
                    Present_Hero->Attack_Base(Present_Hero, Present_Accuracy);
                    Last_Shoot_Tick_Blue=tick;
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero->Get_Pos(), Aim_Robot->Get_Pos()) + Blue[0].Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Hero->Move_to(Present_Hero, Aim_Robot->Get_Pos());
                } else {
                    Present_Hero->Attack_Robot(Present_Hero, Aim_Robot, Present_Accuracy);
                    Last_Shoot_Tick_Blue=tick;
                }
            }
        }
    }
}
