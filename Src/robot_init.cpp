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

static void Robot_Init(){
    Red[0].Robot_Type=Hero;
    Red[0].HP_State={200,200};
    Red[0].Pos_State={0,0};
    Red[0].Remaining_Ammo=30;
    Red[0].Self_Aiming_Para=0.9;
    Red[0].Robot_Level=1;
    Red[0].Robot_Exp=0;
    Red[0].Robot_Speed=1; //单位m/tick
    Red[0].Robot_Number="Red1";
    Red[0].Damage=150;
    Red[0].Revive_Time=0;

    Red[1].Robot_Type=Engineer;
    Red[1].HP_State={250,250};
    Red[1].Pos_State={0,0};
    Red[1].Self_Aiming_Para=0;
    Red[1].Remaining_Ammo=0;
    Red[1].Robot_Level=0;
    Red[1].Robot_Exp=0;
    Red[1].Robot_Speed=2;
    Red[1].Robot_Number="Red2";
    Red[1].Damage=0;
    Red[1].Revive_Time=0;

    Red[2].Robot_Type=Infantry;//方便起见我把所有的步兵都改成平衡步兵了
    Red[2].HP_State={300,300};
    Red[2].Pos_State={0,0};
    Red[2].Remaining_Ammo=150;
    Red[2].Self_Aiming_Para=0.8;
    Red[2].Robot_Level=1;
    Red[2].Robot_Exp=0;
    Red[2].Robot_Speed=2;
    Red[2].Robot_Number="Red3";
    Red[2].Damage=10;
    Red[2].Revive_Time=0;

    Red[3]=Red[2];
    Red[3].Robot_Number="Red4";
    Red[4]=Red[2];
    Red[4].Robot_Number="Red5";

    Red[5].Robot_Type=Sentinel;
    Red[5].HP_State={1000,1000};
    Red[5].Pos_State={0,0};
    Red[5].Self_Aiming_Para=0.7;
    Red[5].Remaining_Ammo=600;
    Red[5].Robot_Level=0;
    Red[5].Robot_Exp=0;
    Red[5].Robot_Speed=3;
    Red[5].Robot_Number="Red6";
    Red[5].Damage=10;
    Red[5].Revive_Time=0;

    Blue[0]=Red[0];
    Blue[1]=Red[1];
    Blue[2]=Red[2];
    Blue[3]=Red[3];
    Blue[4]=Red[4];
    Blue[5]=Red[5];

    Blue[0].Pos_State={28,15};
    Blue[1].Pos_State={28,15};
    Blue[2].Pos_State={28,15};
    Blue[3].Pos_State={28,15};
    Blue[4].Pos_State={28,15};
    Blue[5].Pos_State={28,15};

    Red[0].Robot_Camp=Red_Team;
    Red[1].Robot_Camp=Red_Team;
    Red[2].Robot_Camp=Red_Team;
    Red[3].Robot_Camp=Red_Team;
    Red[4].Robot_Camp=Red_Team;
    Red[5].Robot_Camp=Red_Team;

    Blue[0].Robot_Camp=Blue_Team;
    Blue[1].Robot_Camp=Blue_Team;
    Blue[2].Robot_Camp=Blue_Team;
    Blue[3].Robot_Camp=Blue_Team;
    Blue[4].Robot_Camp=Blue_Team;
    Blue[5].Robot_Camp=Blue_Team;

    Blue[0].Robot_Number="Blue1";
    Blue[1].Robot_Number="Blue2";
    Blue[2].Robot_Number="Blue3";
    Blue[3].Robot_Number="Blue4";
    Blue[4].Robot_Number="Blue5";
    Blue[5].Robot_Number="Blue6";

    Red[6].Robot_Level=-1;
    Blue[6].Robot_Level=-1;
}
