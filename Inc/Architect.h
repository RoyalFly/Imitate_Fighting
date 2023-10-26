//
// Created by 98383 on 2023/10/3.
//

#ifndef IMITATE_FIGHTING_ARCHITECT_H
#define IMITATE_FIGHTING_ARCHITECT_H
#include "robot.h"

class Architecture{
private:
    int HP;
    RobotPos Pos_State;
    const char* Name;
    CampTypeDef Camp;
    Architecture(int hp,RobotPos pos,const char* name, CampTypeDef camp);
public:
    static void Architect_Init();
    inline const char* Get_Name();
    inline int Get_HP();
    inline void HP_Loss(int loss);
    inline CampTypeDef Get_Camp();
    Architecture();
};

inline CampTypeDef Architecture::Get_Camp(){
    return Camp;
}

inline const char* Architecture::Get_Name(){
    return Name;
}

inline int Architecture::Get_HP(){
    return HP;
}

inline void Architecture::HP_Loss(int loss) {
    HP-=loss;
}

void Architect_Init();

#endif//IMITATE_FIGHTING_ARCHITECT_H
