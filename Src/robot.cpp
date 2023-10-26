//
// Created by 98383 on 2023/10/3.
//

#include "..\Inc\robot.h"

//机器人参数初始化
//简化起见所有的车都是幽灵车车
//Self_Aiming_Para是自瞄综合参数，大概就是命中率
//简化需要，弹药的补充发生在工程机器人兑换矿石的时候，每次兑换英雄+30,步兵+150
//简化需要，机器人的底盘保持全功率进行
//Todo:有空的话考虑维护射速问题，不然Hero实在是太IMBA;有空添加升级系统

Robot :: Robot()= default;

Robot Red[7]{};
Robot Blue[7]{};

Robot::Robot(RobotTypeDef TYPE,RobotHP hp, RobotPos pos, float Self_Aiming, int Robot_Level, float Robot_Sp, CampTypeDef Camp, const char *Robot_Num, int Dam, int Revive_Tim) {
    Robot_Type=TYPE;
    HP_State=hp;
    Pos_State=pos;
    Self_Aiming_Para=Self_Aiming;
    Robot_Speed=Robot_Sp;
    Robot_Camp=Camp;
    Robot_Number=Robot_Num;
    Damage=Dam;
    Revive_Time=Revive_Tim;
}
void Robot :: Robot_Init(){
    Red[0]=Robot(Hero,{200,200},{0,0},0.9,1,1,Red_Team,"Red1",150,0);
    Blue[0]=Robot(Hero,{200,200},{28,15},0.9,1,1,Blue_Team,"Blue1",150,0);
    Red[1]=Robot(Engineer,{250,250},{0,0},0,0,2,Red_Team,"Red2",0,0);
    Blue[1]=Robot(Engineer,{250,250},{28,15},0,0,2,Blue_Team,"Blue2",0,0);
    Red[2]=Robot(Infantry,{300,300},{0,0},0.8,1,2,Red_Team,"Red3",50,0);
    Blue[2]=Robot(Infantry,{300,300},{28,15},0.8,1,2,Blue_Team,"Blue3",50,0);
    Red[3]=Robot(Infantry,{300,300},{0,0},0.8,1,2,Red_Team,"Red4",50,0);
    Blue[3]=Robot(Infantry,{300,300},{28,15},0.8,1,2,Blue_Team,"Blue4",50,0);
    Red[4]=Robot(Infantry,{300,300},{0,0},0.8,1,2,Red_Team,"Red5",50,0);
    Blue[4]=Robot(Infantry,{300,300},{28,15},0.8,1,2,Blue_Team,"Blue5",50,0);
    Red[5]=Robot(Sentinel,{1000,1000},{0,0},0.7,0,3,Red_Team,"Red6",50,0);
    Blue[5]=Robot(Sentinel,{1000,1000},{28,15},0.7,0,3,Blue_Team,"Blue6",50,0);
    Red[6]=Robot(Engineer,{0,0},{0,0},0,-1,0,Red_Team,"qwq",0,0);
    Blue[6]=Robot(Engineer,{0,0},{0,0},0,-1,0,Blue_Team,"qwq",0,0);
}
