//
// Created by 98383 on 2023/10/6.
//

#include "..\Inc\Infantry.h"
#include "..\Inc\Action.h"

extern Tower Blue_Tower,Red_Tower;
extern Base Red_Base,Blue_Base;

const float Accuracy_Loss=0.07;

void Action_Infantry(Robot* Present_Robot){
    if (Present_Robot->Revive_Time > 0){
        Present_Robot->Revive_Time--;
        if (Present_Robot->Revive_Time == 0){
            Present_Robot->HP_State.hp=Present_Robot->HP_State.max_hp;
        }
        return;
    }
    //索敌顺序：敌人>塔>基地
    Robot* Aim_Robot = Searching_Enemy(Present_Robot); // Searching_Enemy需要返回一个机器人类型的指针
    if (Present_Robot->Robot_Camp == Red_Team) {
        if (Blue_Tower.HP != 0 && Aim_Robot->Robot_Level == -1) {//如果塔没掉敌人全部被歼灭则推塔
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Pos_State, Blue_Tower.Pos_State) + Present_Robot->Self_Aiming_Para;
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Robot->Pos_State=Move_to(Present_Robot, Blue_Tower.Pos_State);
            } else {
                Attack_Tower(Present_Robot, &Blue_Tower, Present_Accuracy);
            }
        } else {
            if (Aim_Robot->Robot_Level == -1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Pos_State, Blue_Base.Pos_State) + Present_Robot->Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Pos_State=Move_to(Present_Robot, Blue_Base.Pos_State);
                } else {
                    Attack_Base(Present_Robot, &Blue_Base, Present_Accuracy);
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Pos_State, Aim_Robot->Pos_State) + Present_Robot->Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Pos_State=Move_to(Present_Robot, Aim_Robot->Pos_State);
                } else {
                    Attack_Robot(Present_Robot, Aim_Robot, Present_Accuracy);
                }
            }
        }
    } else {
        if (Red_Tower.HP != 0 && Aim_Robot->Robot_Level == -1) {
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Pos_State, Red_Tower.Pos_State) + Present_Robot->Self_Aiming_Para;
            if (Present_Accuracy < 0.5) {//命中率太低，执行移动操作
                Present_Robot->Pos_State=Move_to(Present_Robot, Red_Tower.Pos_State);
            } else {
                Attack_Tower(Present_Robot, &Red_Tower, Present_Accuracy);
            }
        } else {
            if (Aim_Robot->Robot_Level == -1) {//敌军已被歼灭
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Pos_State, Red_Base.Pos_State) + Present_Robot->Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Pos_State=Move_to(Present_Robot, Blue_Base.Pos_State);
                } else {
                    Attack_Base(Present_Robot, &Blue_Base, Present_Accuracy);
                }
            } else {//找到目标敌军
                float Present_Accuracy = -Accuracy_Loss * dist(Present_Robot->Pos_State, Aim_Robot->Pos_State) + Present_Robot->Self_Aiming_Para;
                if (Present_Accuracy < 0.8) {
                    Present_Robot->Pos_State=Move_to(Present_Robot, Aim_Robot->Pos_State);
                } else {
                    Attack_Robot(Present_Robot, Aim_Robot, Present_Accuracy);
                }
            }
        }
    }
}