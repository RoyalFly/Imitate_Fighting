//
// Created by 98383 on 2023/10/4.
//

#include <cstdio>
#include <ctime>
#include <random>
#include <string>
#include <chrono>
#include "..\Inc\TypeDefine.h"
#include "..\Inc\robot.h"


static int Re_CD=60; //复活时间

extern Robot Red[7],Blue[7];
extern Architecture Red_Tower,Blue_Tower;
extern Architecture Red_Base,Blue_Base;

float dist(RobotPos obj1, RobotPos obj2) {
    return (float) sqrt((double) (obj1.x - obj2.x) * (obj1.x - obj2.x) + (obj1.y - obj2.y) * (obj1.y - obj2.y));
}

int max(int x, int y) {
    if (x > y) return x;
    else
        return y;
}

void Robot :: Move_to(Robot* Present_Robot, RobotPos Des_Pos) {  //移动
    float dis = dist(Present_Robot->Pos_State, Des_Pos);
    float tmp=Present_Robot->Robot_Speed;
    if (dis < Present_Robot->Robot_Speed){
        Present_Robot->Robot_Speed=dis;
    }
    float vec_x = (-Present_Robot->Pos_State.x + Des_Pos.x) / dis;
    float vec_y = (-Present_Robot->Pos_State.y + Des_Pos.y) / dis;
    RobotPos End_Pos = {Present_Robot->Pos_State.x+vec_x * Present_Robot->Robot_Speed, Present_Robot->Pos_State.y+vec_y * Present_Robot->Robot_Speed};
    puts(Present_Robot->Robot_Number);
    std::printf("from %.2f,%.2f to %.2f,%.2f\n", Present_Robot->Pos_State.x, Present_Robot->Pos_State.y, End_Pos.x, End_Pos.y);
    Present_Robot->Robot_Speed=tmp;
    Pos_State = End_Pos;
}

void Robot :: Attack_Tower(Robot* Attacker, float Accuracy) {  //进攻敌方先锋塔
    srand( std::chrono::system_clock::now().time_since_epoch().count() );
    int tmp=rand()%1000;
    float judge=(float)tmp/1000;
    if (Attacker->Robot_Camp == Red_Team){
        if (judge > Accuracy) {//未命中
            puts(Attacker->Robot_Number);
            printf(" fail to shoot ");
            puts("Blue_Tower");
            printf("\n");
            return;
        }
        puts(Attacker->Robot_Number);
        printf("hits ");
        puts("Blue_Tower");
        printf(",whose HP drops from %d to %d\n", Blue_Tower.Get_HP(), max(Blue_Tower.Get_HP() - Attacker->Damage, 0));
        Blue_Tower.HP_Loss(max(0, Blue_Tower.Get_HP() - Attacker->Damage));
        if (Blue_Tower.Get_HP() == 0) {
            puts(Blue_Tower.Get_Name());
            printf("has been destroyed\n");
        }
    } else {
        if (judge > Accuracy) {//未命中
            puts(Attacker->Robot_Number);
            printf(" fail to shoot ");
            puts("Red_Tower");
            printf("\n");
            return;
        }
        puts(Attacker->Robot_Number);
        printf("hits ");
        puts("Red_Tower");
        printf(",whose HP drops from %d to %d\n", Red_Tower.Get_HP(), max(Red_Tower.Get_HP() - Attacker->Damage, 0));
        Red_Tower.HP_Loss(max(0, Red_Tower.Get_HP() - Attacker->Damage));
        if (Red_Tower.Get_HP() == 0) {
            puts(Red_Tower.Get_Name());
            printf("has been destroyed\n");
        }
    }

}

void Robot :: Attack_Base(Robot* Attacker, float Accuracy) { //进攻敌方基地
    srand( std::chrono::system_clock::now().time_since_epoch().count() );
    int tmp=rand()%1000;
    float judge=(float)tmp/1000;
    if (Attacker->Robot_Camp == Red_Team){
        if (judge > Accuracy) {
            puts(Attacker->Robot_Number);
            printf(" fail to shoot ");
            puts("Blue_Base");
            printf("\n");
            return;
        }
        puts(Attacker->Robot_Number);
        printf("hits ");
        puts("Blue_Base");
        printf(",whose HP drops from %d to %d\n", Blue_Base.Get_HP(), max(Blue_Base.Get_HP() - Attacker->Damage, 0));
        Blue_Base.HP_Loss(max(0, Blue_Base.Get_HP() - Attacker->Damage));
        if (Blue_Base.Get_HP() == 0) {
            puts(Blue_Base.Get_Name());
            printf("has been destroyed\n");
            printf("Red Team Wins\n");
            return;
        }
    } else {
        if (judge > Accuracy) {
            puts(Attacker->Robot_Number);
            printf(" fail to shoot ");
            puts("Red_Base");
            printf("\n");
            return;
        }
        puts(Attacker->Robot_Number);
        printf("hits ");
        puts("Red_Base");
        printf(",whose HP drops from %d to %d\n", Red_Base.Get_HP(), max(Red_Base.Get_HP() - Attacker->Damage, 0));
        Red_Base.HP_Loss(max(0, Red_Base.Get_HP() - Attacker->Damage));
        if (Red_Base.Get_HP() == 0) {
            puts(Red_Base.Get_Name());
            printf("has been destroyed\n");
            printf("Blue Team Wins\n");
            return;
        }
    }


}

Robot* Robot :: Searching_Enemy(Robot* Present_Robot){  // 索敌
    Robot* Aim;
    if (Present_Robot->Robot_Camp == Red_Team){
        float Min_Dist=100000;
        Aim=&Blue[6];
        for (int i=0;i<=5;i++){
            if (Blue[i].HP_State.hp == 0){
                continue;
            }
            float dis=dist(Present_Robot->Pos_State,Blue[i].Pos_State);
            if (dis<Min_Dist){
                Min_Dist=dis;
                Aim=&Blue[i];
            }
        }
    } else {
        float Min_Dist=100000;
        Aim=&Red[6];
        for (int i=0;i<=5;i++){
            if (Red[i].HP_State.hp == 0){
                continue;
            }
            float dis=dist(Present_Robot->Pos_State,Red[i].Pos_State);
            if (dis<Min_Dist){
                Min_Dist=dis;
                Aim=&Red[i];
            }
        }
    }
    return Aim;
}

void Robot :: Attack_Robot(Robot* Attacker,Robot* Aim,float Accuracy){
    srand( std::chrono::system_clock::now().time_since_epoch().count() );
    int tmp=rand()%1000;
    float judge=(float)tmp/1000;
    if (judge > Accuracy) {
        puts(Attacker->Robot_Number);
        printf(" fail to shoot ");
        puts(Aim->Robot_Number);
        printf("\n");
        return;
    }
    puts(Attacker->Robot_Number);
    printf("hits ");
    puts(Aim->Robot_Number);
    printf(",whose HP drops from %d to %d\n", Aim->HP_State.hp, max(Aim->HP_State.hp - Attacker->Damage, 0));
    Aim->HP_Loss(max(0, Aim->HP_State.hp - Attacker->Damage));
    if (Aim->HP_State.hp == 0) {
        puts(Aim->Robot_Number);
        printf("has been destroyed\n");
        Aim->Revive_Time=Re_CD;
    }
}
