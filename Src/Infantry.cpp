//
// Created by 98383 on 2023/10/6.
//

#include "..\Inc\Infantry.h"
#include "..\Inc\Action.h"

extern Architecture Blue_Tower,Red_Tower;
extern Architecture Red_Base,Blue_Base;

const float Accuracy_Loss=0.07;

void Action_Infantry(Robot* Present_Robot){
    if (Present_Robot->Get_Reviving_Time() > 0){
        Present_Robot->Reviving();
        if (Present_Robot->Get_Reviving_Time() == 0){
            Present_Robot->Revive();
        }
        return;
    }
    //索敌顺序：敌人>塔>基地
    Robot* Aim_Robot = Present_Robot->Searching_Enemy(Present_Robot); // Searching_Enemy需要返回一个机器人类型的指针
    if (Present_Robot->Get_Camp() == Red_Team) {
        if (Blue_Tower.Get_HP() != 0 && Aim_Robot->Get_Level() == -1) {//如果塔没掉敌人全部被歼灭则推塔
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Get_Pos(), Blue_Tower.Get_Pos()) + Present_Robot->Get_Self_Aiming();
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Robot->Move_to(Present_Robot, Blue_Tower.Get_Pos());
            } else {
                Present_Robot->Attack_Tower(Present_Robot,Present_Accuracy);
            }
        } else {
            if (Aim_Robot->Get_Level() != 1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Get_Pos(), Blue_Base.Get_Pos()) + Present_Robot->Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Move_to(Present_Robot, Blue_Base.Get_Pos());
                } else {
                    Present_Robot->Attack_Base(Present_Robot,Present_Accuracy);
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Get_Pos(), Aim_Robot->Get_Pos()) + Present_Robot->Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Move_to(Present_Robot, Aim_Robot->Get_Pos());
                } else {
                    Present_Robot->Attack_Robot(Present_Robot, Aim_Robot, Present_Accuracy);
                }
            }
        }
    } else {
        if (Red_Tower.Get_HP() != 0 && Aim_Robot->Get_Level() == -1) {
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Get_Pos(), Red_Tower.Get_Pos()) + Present_Robot->Get_Self_Aiming();
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Robot->Move_to(Present_Robot, Red_Tower.Get_Pos());
            } else {
                Present_Robot->Attack_Tower(Present_Robot, Present_Accuracy);
            }
        } else {
            if (Aim_Robot->Get_Level() != 1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Get_Pos(), Red_Base.Get_Pos()) + Present_Robot->Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Move_to(Present_Robot, Blue_Base.Get_Pos());
                } else {
                    Present_Robot->Attack_Base(Present_Robot, Present_Accuracy);
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Get_Pos(), Aim_Robot->Get_Pos()) + Present_Robot->Get_Self_Aiming();
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Move_to(Present_Robot, Aim_Robot->Get_Pos());
                } else {
                    Present_Robot->Attack_Robot(Present_Robot, Aim_Robot, Present_Accuracy);
                }
            }
        }
    }
}