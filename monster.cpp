﻿#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

#include "monster.h"
#include "funkcje.h"

m Monster::monsters[];
int Monster::Num_monst;

void Monster::test()
{
    for(int i=1;i<=Num_monst;i++)
    {
        std::cout<<monsters[i].name.c_str()<<std::endl;
        std::cout<<monsters[i].hp<<std::endl;
        std::cout<<monsters[i].attack<<std::endl;
        std::cout<<monsters[i].defence<<std::endl;
    }
}

void Monster::showstats(int hpbattle)
{
    std::cout<<"Statystyki przeciwnika:"<<std::endl;
    std::cout<<"Nazwa: "<<name<<std::endl;
    std::cout<<"Punkty życia: "<<hpbattle<<std::endl;
    std::cout<<"Atak: "<<attack<<std::endl;
    std::cout<<"Obrona: "<<defence<<std::endl<<std::endl;
}

int Monster::getHp()
{
    return hp;
}

int Monster::getAtt()
{
    return attack;
}

int Monster::getDef()
{
    return defence;
}

std::string Monster::getName()
{
    return name;
}

void Monster::Bardzo_Fajna_Funkcja_Do_Sprytnego_Balansowania_Atrybuow_Potwora_Aby_Rozgrywka_Byla_Wyrownana(int pozycja_gracza)
{
     this->hp=std::max(10,(int)((long double)hp*(long double)pozycja_gracza/15L));
     this->attack=std::max(10,(int)((long double)attack*(long double)pozycja_gracza/15L));
     this->defence=std::max(10,(int)((long double)defence*(long double)pozycja_gracza/15L));
}


Monster::Monster()
{
    int x=(rand()%Num_monst)+1;
    name=monsters[x].name;
    hp=monsters[x].hp;
    attack=monsters[x].attack;
    defence=monsters[x].defence;
}

void Monster::boss(int player_points, Player* player)
{
    hp=50-5*player_points;
    attack=50-5*player_points;
    defence=50-5*player_points;
    Bardzo_Fajna_Funkcja_Do_Sprytnego_Balansowania_Atrybuow_Potwora_Aby_Rozgrywka_Byla_Wyrownana(player->GetPos());
    name="Sir Kamiński";
}
