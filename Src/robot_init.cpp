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

void Robot_Init(){
    Red_r1.Robot_Type=Hero;
    Red_r1.HP_State={150,150};
    Red_r1.Pos_State={0,0};
    Red_r1.Remaining_Ammo=30;
    Red_r1.Self_Aiming_Para=0.6;
    Red_r1.Robot_Level=1;
    Red_r1.Robot_Exp=0;
    Red_r1.Robot_Speed=65;

    Red_r2.Robot_Type=Engineer;
    Red_r2.HP_State={250,250};
    Red_r2.Pos_State={0,0};
    Red_r2.Self_Aiming_Para=0;
    Red_r2.Remaining_Ammo=0;
    Red_r2.Robot_Level=0;
    Red_r2.Robot_Exp=0;
    Red_r2.Robot_Speed=100;

    Red_r3.Robot_Type=Infantry;//方便起见我把所有的步兵都改成平衡步兵了
    Red_r3.HP_State={300,300};
    Red_r3.Pos_State={0,0};
    Red_r3.Remaining_Ammo=150;
    Red_r3.Self_Aiming_Para=0.8;
    Red_r3.Robot_Level=1;
    Red_r3.Robot_Exp=0;
    Red_r3.Robot_Speed=100;

    Red_r4=Red_r3;
    Red_r5=Red_r3;

    Red_r6.Robot_Type=Sentinel;
    Red_r6.HP_State={1000,1000};
    Red_r6.Pos_State={0,0};
    Red_r6.Self_Aiming_Para=0.7;
    Red_r6.Remaining_Ammo=600;
    Red_r6.Robot_Level=0;
    Red_r6.Robot_Exp=0;
    Red_r6.Robot_Speed=150;

    Blue_r1=Red_r1;
    Blue_r2=Red_r2;
    Blue_r3=Red_r3;
    Blue_r4=Red_r4;
    Blue_r5=Red_r5;
    Blue_r6=Red_r6;

    Blue_r1.Pos_State={28,15};
    Blue_r2.Pos_State={28,15};
    Blue_r3.Pos_State={28,15};
    Blue_r4.Pos_State={28,15};
    Blue_r5.Pos_State={28,15};
    Blue_r6.Pos_State={28,15};
}
