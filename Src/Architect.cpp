//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\Architect.h"

//总体场地28m x 15m
float width = 15, length = 28;


Architecture::Architecture()= default;

Architecture::Architecture(int hp, RobotPos pos, const char *name, CampTypeDef camp) {
    HP=hp;
    Pos_State=pos;
    Name=name;
    Camp=camp;
}

Architecture Red_Tower,Blue_Tower;
Architecture Red_Base,Blue_Base;

void Architecture::Architect_Init() {
    Red_Base=Architecture(5000,{0,(float)0.5*width},"Red Base",Red_Team);
    Blue_Base=Architecture(5000,{length,(float)0.5*width},"Blue Base",Blue_Team);
    Red_Tower=Architecture(1500,{(float)1.0/3*length,(float)1.0/3*width},"Red Tower",Red_Team);
    Red_Tower=Architecture(1500,{(float) 2.0 / 3 * length,(float) 2.0 / 3 * width},"Blue Tower",Blue_Team);
}