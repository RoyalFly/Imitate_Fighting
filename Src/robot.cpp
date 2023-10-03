//
// Created by 98383 on 2023/10/3.
//

#include "../Inc/robot.h"

RobotPos* moveRobot(RobotPos *pos, float dx, float dy){
    pos->x = pos->x + dx;
    pos->y = pos->y + dy;
    return pos;
}