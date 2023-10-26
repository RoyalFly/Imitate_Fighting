//
// Created by 98383 on 2023/10/26.
//

#ifndef IMITATE_FIGHTING_TYPEDEFINE_H
#define IMITATE_FIGHTING_TYPEDEFINE_H

struct RobotPos {
    float x;
    float y;
};

struct RobotHP {
    int hp;
    int max_hp;
};

typedef enum {
    Engineer,
    Infantry,
    Sentinel,
    Hero
} RobotTypeDef;

typedef enum {
    Red_Team,
    Blue_Team
} CampTypeDef;

#endif//IMITATE_FIGHTING_TYPEDEFINE_H
