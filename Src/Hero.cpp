//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\Architect.h"
#include "..\Inc\robot.h"
#include "random"

float Accuracy_Loss = 0.03;// 每远离目标1m，精准度下降0.03

float dist(RobotPos obj1, RobotPos obj2) {
    return (float) sqrt((double) (obj1.x - obj2.x) * (obj1.x - obj2.x) + (obj1.y - obj2.y) * (obj1.y - obj2.y));
}

void Action_Hero(Robot Present_Hero) {
    if (Present_Hero.Robot_Camp == Red_Team) {
        if (Blue_Tower.HP != 0) {//优先执行对先锋塔吊射
            float Present_Accuracy = -Accuracy_Loss * dist(Present_Hero.Pos_State, Blue_Tower.Pos_State) + Red[0].Self_Aiming_Para;
        }
    }
}
