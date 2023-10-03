//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\robot.h"
#include "..\Inc\Architect.h"
#include "random"

float Accuracy_Loss=0.03;// 每远离目标1m，精准度下降0.03

void Action_Hero(Robot Present_Hero){
    if (Present_Hero.Robot_Camp == Red_Team){
        if (Blue_Tower.HP != 0){  //优先执行对先锋塔吊射
            float Present_Accuracy=-Accuracy_Loss*dist(Present_Hero.Pos_State,)
        }
    }
}