#include "../Inc/robot.h"
#include "robot_init.cpp"
#include "Architect_init.cpp"
#include "Tick_Simulate.cpp"
#include "random"

int tick=0; //作为模拟系统的计时单位，一些长于1tick的操作需要基于这个变量

int main() {
    Robot_Init();
    Architect_Init();
    //主要行动逻辑：先索最近的敌方车辆，判定是否进入射程决定这个tick是移动还是射击
    //我好像把这个游戏做成回合制了qwq
    while (1){
        tick++;
        Tick_Simulate();
    }
}
