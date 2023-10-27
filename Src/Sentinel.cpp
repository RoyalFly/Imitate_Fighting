//
// Created by 98383 on 2023/10/4.
//

#include "..\Inc\Architect.h"
#include "..\Inc\robot.h"
#include "..\Inc\Action.h"

//哨兵主要逻辑：死守先锋塔（大概率会面对敌方步兵的冲击），能打一个是一个吧

const float Accuracy_Loss = 0.05;
extern int tick;
extern Architecture Red_Tower,Blue_Tower;
extern Architecture Red_Base,Blue_Base;

void Action_Sentinel(Robot* Present_Robot) {
    if (Present_Robot->Get_HP() == 0) {
        return;
    }
    if (Present_Robot->Get_Camp() == Red_Team) {
        if (Present_Robot->Get_Pos().x != Red_Tower.Get_Pos().x || Present_Robot->Get_Pos().y != Red_Tower.Get_Pos().y) {
            Present_Robot->Move_to(Present_Robot, Red_Tower.Get_Pos());
            return;
        }
        Robot *Aim = Present_Robot->Searching_Enemy(Present_Robot);
        float Current_Accuracy=-Accuracy_Loss* dist(Present_Robot->Get_Pos(),Aim->Get_Pos())+Present_Robot->Get_Self_Aiming();
        Present_Robot->Attack_Robot(Present_Robot,Aim,Current_Accuracy);
    } else {
        if (Present_Robot->Get_Pos().x != Blue_Tower.Get_Pos().x || Present_Robot->Get_Pos().y != Blue_Tower.Get_Pos().y) {
            Present_Robot->Move_to(Present_Robot, Blue_Tower.Get_Pos());
            return;
        }
        Robot *Aim = Present_Robot->Searching_Enemy(Present_Robot);
        float Current_Accuracy=-Accuracy_Loss* dist(Present_Robot->Get_Pos(),Aim->Get_Pos())+Present_Robot->Get_Self_Aiming();
        Present_Robot->Attack_Robot(Present_Robot,Aim,Current_Accuracy);
    }
}