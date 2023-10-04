//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\Architect.h"

//总体场地28m x 15m
static float width = 15, length = 28;

static void Architect_Init() {
    Red_Base.Pos_State.x = 0;
    Red_Base.Pos_State.y = (float) 0.5 * width;
    Red_Base.Armour = true;
    Red_Base.HP = 5000;
    Red_Base.Name = "Red Base";
    Red_Base.Camp=Red_Team;
    Blue_Base.Pos_State.x = length;
    Blue_Base.Pos_State.y = (float) 0.5 * width;
    Blue_Base.Armour = true;
    Blue_Base.HP = 5000;
    Blue_Base.Name = "Blue Base";
    Blue_Base.Camp=Blue_Team;

    Red_Tower.Pos_State.x = (float) 1.0 / 3 * length;
    Red_Tower.Pos_State.y = (float) 1.0 / 3 * width;
    Red_Tower.HP = 1500;
    Red_Tower.Name = "Red Tower";
    Blue_Tower.Pos_State.x = (float) 2.0 / 3 * length;
    Blue_Tower.Pos_State.y = (float) 2.0 / 3 * width;
    Blue_Tower.HP = 1500;
    Blue_Tower.Name = "Blue Tower";
}