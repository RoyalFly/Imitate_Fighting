//
// Created by 98383 on 2023/10/4.
//

#include <cstdio>
#include <ctime>
#include <random>
#include <string>
#include <chrono>

const int Re_CD=30; //复活时间

static float dist(RobotPos obj1, RobotPos obj2) {
    return (float) sqrt((double) (obj1.x - obj2.x) * (obj1.x - obj2.x) + (obj1.y - obj2.y) * (obj1.y - obj2.y));
}

static int max(int x, int y) {
    if (x > y) return x;
    else
        return y;
}

static RobotPos Move_to(Robot* Present_Robot, RobotPos Des_Pos) {  //移动
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
    return End_Pos;
}

static void Attack_Tower(Robot* Attacker, Tower *Aimed_Tower, float Accuracy) {  //进攻敌方先锋塔
    srand( std::chrono::system_clock::now().time_since_epoch().count() );
    int tmp=rand()%1000;
    float judge=(float)tmp/1000;
    printf("%.3f %.3f\n",judge,Accuracy);
    if (judge > Accuracy) {//未命中
        puts(Attacker->Robot_Number);
        printf(" fail to shoot ");
        puts(Aimed_Tower->Name);
        printf("\n");
        return;
    }
    puts(Attacker->Robot_Number);
    printf("hits ");
    puts(Aimed_Tower->Name);
    printf(",whose HP drops from %d to %d\n", Aimed_Tower->HP, max(Aimed_Tower->HP - Attacker->Damage, 0));
    Aimed_Tower->HP = max(0, Aimed_Tower->HP - Attacker->Damage);
    if (Aimed_Tower->HP == 0) {
        puts(Aimed_Tower->Name);
        printf("has been destroyed\n");
    }
}

static void Attack_Base(Robot* Attacker, Base *Aimed_Base, float Accuracy) { //进攻敌方基地
    srand( std::chrono::system_clock::now().time_since_epoch().count() );
    int tmp=rand()%1000;
    float judge=(float)tmp/1000;
    if (judge > Accuracy) {
        puts(Attacker->Robot_Number);
        printf(" fail to shoot ");
        puts(Aimed_Base->Name);
        printf("\n");
        return;
    }
    puts(Attacker->Robot_Number);
    printf("hits ");
    puts(Aimed_Base->Name);
    printf(",whose HP drops from %d to %d\n", Aimed_Base->HP, max(Aimed_Base->HP - Attacker->Damage, 0));
    Aimed_Base->HP = max(0, Aimed_Base->HP - Attacker->Damage);
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

static Robot* Searching_Enemy(Robot* Present_Robot){  // 索敌
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

static void Attack_Robot(Robot* Attacker,Robot* Aim,float Accuracy){
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
    Aim->HP_State.hp = max(0, Aim->HP_State.hp - Attacker->Damage);
    if (Aim->HP_State.hp == 0) {
        puts(Aim->Robot_Number);
        printf("has been destroyed\n");
        Aim->Revive_Time=Re_CD;
    }
}
