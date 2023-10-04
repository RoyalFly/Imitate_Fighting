//
// Created by 98383 on 2023/10/4.
//

#include "..\Inc\Architect.h"
#include "..\Inc\main.h"
#include "..\Inc\robot.h"
#include <cstdio>
#include <ctime>
#include <random>
#include <string>

float dist(RobotPos obj1, RobotPos obj2) {
    return (float) sqrt((double) (obj1.x - obj2.x) * (obj1.x - obj2.x) + (obj1.y - obj2.y) * (obj1.y - obj2.y));
}

int max(int x, int y) {
    if (x > y) return x;
    else
        return y;
}

float min(float x,float y){
    if (x<y) return y;
    else return x;
}

RobotPos Move_to(Robot Present_Robot, RobotPos Des_Pos) {
    float dis = dist(Present_Robot.Pos_State, Des_Pos);
    float vec_x = (Present_Robot.Pos_State.x - Des_Pos.x) / dis;
    float vec_y = (Present_Robot.Pos_State.y - Des_Pos.y) / dis;
    RobotPos End_Pos = {vec_x * Present_Robot.Robot_Speed, vec_y * Present_Robot.Robot_Speed};
    puts(Present_Robot.Robot_Number);
    std::printf("from %.2f,%.2f to %.2f,%.2f\n", Present_Robot.Pos_State.x, Present_Robot.Pos_State.y, End_Pos.x, End_Pos.y);
    return End_Pos;
}

void Attack_Tower(Robot Attacker, Tower *Aimed_Tower, float Accuracy) {
    srand(time(nullptr));
    int tmp = rand() % 1000;
    float judge = (float) tmp / 1000;
    if (judge > Accuracy) {//未命中
        puts(Attacker.Robot_Number);
        printf(" fail to shoot ");
        puts(Aimed_Tower->Name);
        printf("\n");
        return;
    }
    puts(Attacker.Robot_Number);
    printf("hits ");
    puts(Aimed_Tower->Name);
    printf(",whose HP drops from %d to %d\n", Aimed_Tower->HP, max(Aimed_Tower->HP - Attacker.Damage, 0));
    Aimed_Tower->HP = max(0, Aimed_Tower->HP - Attacker.Damage);
    if (Aimed_Tower->HP == 0) {
        puts(Aimed_Tower->Name);
        printf("has been destroyed\n");
    }
}

void Attack_Base(Robot Attacker, Base *Aimed_Base, float Accuracy) {
    srand(time(nullptr));
    int tmp = rand() % 1000;
    float judge = (float) tmp / 1000;
    if (judge > Accuracy) {
        puts(Attacker.Robot_Number);
        printf(" fail to shoot ");
        puts(Aimed_Base->Name);
        printf("\n");
        return;
    }
    puts(Attacker.Robot_Number);
    printf("hits ");
    puts(Aimed_Base->Name);
    printf(",whose HP drops from %d to %d\n", Aimed_Base->HP, max(Aimed_Base->HP - Attacker.Damage, 0));
    Aimed_Base->HP = max(0, Aimed_Base->HP - Attacker.Damage);
    if (Aimed_Base->HP == 0) {
        puts(Aimed_Base->Name);
        printf("has been destroyed\n");
        if (Aimed_Base->Camp == Red_Team){
            printf("Blue Team Wins\n");
            return;
        } else {
            printf("Red Team Wins\n");
            return;
        }
    }
}

Robot* Searching_Enemy(Robot Present_Robot){
    Robot* Aim;
    if (Present_Robot.Robot_Camp == Red_Team){
        float Min_Dist=100000;
        Aim=&Blue[0];
        Aim->Robot_Level=-1;
        for (int i=0;i<=5;i++){
            if (Blue[i].HP_State.hp == 0){
                continue;
            }
            float dis=dist(Present_Robot.Pos_State,Blue[i].Pos_State);
            if (dis<Min_Dist){
                Min_Dist=dis;
                Aim=&Blue[i];
            }
        }
    } else {
        float Min_Dist=100000;
        Aim=&Red[0];
        Aim->Robot_Level=-1;
        for (int i=0;i<=5;i++){
            if (Red[i].HP_State.hp == 0){
                continue;
            }
            float dis=dist(Present_Robot.Pos_State,Red[i].Pos_State);
            if (dis<Min_Dist){
                Min_Dist=dis;
                Aim=&Red[i];
            }
        }
    }
    return Aim;
}