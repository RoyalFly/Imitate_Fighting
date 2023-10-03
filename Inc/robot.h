//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ROBOT_H
#define IMITATE_FIGHTING_ROBOT_H


struct RobotPos{
    float x;
    float y;
    float yaw;
    float pitch;
};

RobotPos* moveRobot(RobotPos *pos,float dx,float dy);

struct RobotHP{
    int hp;
    int max_hp;
};


#endif//IMITATE_FIGHTING_ROBOT_H
