//
// Created by 98383 on 2023/10/4.
//

#include "..\Inc\Architect.h"
#include "..\Inc\robot.h"
#include "..\Inc\Action.h"

//哨兵主要逻辑：死守先锋塔（大概率会面对敌方步兵的冲击），能打一个是一个吧

const float Accuracy_Loss = 0.05;
extern int tick;
extern Tower Red_Tower,Blue_Tower;
extern Base Red_Base,Blue_Base;

void Action_Sentinel(Robot* Present_Robot) {
    if (Present_Robot->HP_State.hp == 0) {
        return;
    }
    if (Present_Robot->Robot_Camp == Red_Team) {
        if (Present_Robot->Pos_State.x != Red_Tower.Pos_State.x || Present_Robot->Pos_State.y != Red_Tower.Pos_State.y) {
            Present_Robot->Pos_State=Move_to(Present_Robot, Red_Tower.Pos_State);
            return;
        }
        Robot *Aim = Searching_Enemy(Present_Robot);
        float Current_Accuracy=-Accuracy_Loss* dist(Present_Robot->Pos_State,Aim->Pos_State)+Present_Robot->Self_Aiming_Para;
        Attack_Robot(Present_Robot,Aim,Current_Accuracy);
    } else {
        if (Present_Robot->Pos_State.x != Blue_Tower.Pos_State.x || Present_Robot->Pos_State.y != Blue_Tower.Pos_State.y) {
            Present_Robot->Pos_State=Move_to(Present_Robot, Blue_Tower.Pos_State);
            return;
        }
        Robot *Aim = Searching_Enemy(Present_Robot);
        float Current_Accuracy=-Accuracy_Loss* dist(Present_Robot->Pos_State,Aim->Pos_State)+Present_Robot->Self_Aiming_Para;
        Attack_Robot(Present_Robot,Aim,Current_Accuracy);
    }
}