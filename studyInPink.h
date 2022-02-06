/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void Makesense_E(int &x)
{
    if(x > 900) x = 900;
    else if(x < 0) x = 0;
}
void Makesense_H(int &x)
{
    if(x > 999) x = 999;
    else if(x < 0) x = 0;
}
void Makesense_M(int &x)
{
    if(x > 2000) x = 2000;
    else if(x < 0) x = 0;
}
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    if(E1 < 0 || E1 > 999) return -999;

    Makesense_E(EXP1); 
    Makesense_E(EXP2);
    if(E1 >= 0 && E1 < 50)
    {
        EXP2 += 25;
    }
    else if(E1 < 100)
    {
        EXP2 += 50;
    }
    else if(E1 < 150)
    {
        EXP2 += 85;
    }
    else if(E1 < 200)
    {
        EXP2 += 75;
    }
    else if(E1 < 250)
    {
        EXP2 += 110;
    }
    else if(E1 < 300)
    {
        EXP2 += 135;
    }
    else if(E1 < 400)
    {
        EXP2 += 160;
    }
    else if(E1 < 500)
    {
        EXP2 = ceil(double(EXP2) + (double(E1) / 7 + 9));
    }
    else if(E1 < 600)
    {
        EXP2 = ceil(double(EXP2) + (double(E1) / 9 + 11));
    }
    else if(E1 < 700)
    {
        EXP2 = ceil(double(EXP2) + (double(E1) / 5 + 6));
    }
    else if(E1 < 800)
    {
        EXP2 = ceil(double(EXP2) + (double(E1) / 7 + 9));
        if(EXP2 > 200)
        {
            EXP2 = ceil(double(EXP2) + (double(E1) / 9 + 11));
        }
    }
    else
    {
        EXP2 = ceil(double(EXP2) + (double(E1) / 7 + 9));
        EXP2 = ceil(double(EXP2) + (double(E1) / 9 + 11));
        if(EXP2 > 600)
        {
            EXP2 = ceil(double(EXP2) + (double(E1) / 5 + 6));
            EXP2 = ceil(double(EXP2) * 1.15);
        }
    }
    //For Sherlock Holmes
    if(E1 >= 400)
    {
        EXP1 = ceil(double(EXP1) - double(E1) / 10);
    }
    else
    {
        if(E1 % 2)
        {
            EXP1 = ceil(double(EXP1) + (double(E1) / 10));
        }
        else
        {
            EXP1 = ceil(double(EXP1) - (double(E1) / 5));
        }
    }
    Makesense_E(EXP1); Makesense_E(EXP2);
    return EXP1 + EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    if(E2 < 0 || E2 > 999) return -999;

    Makesense_H(HP2);
    Makesense_M(M2);
    //The first period
    double d1 = double(E2) / 9 + 10;
    double d2 = double(E2) * 0.35;
    double d3 = (d1 + d2) * 0.17;
    if(E2 >= 0 && E2 < 300)
    {
        EXP2 = ceil(double(EXP2) + d1);
        EXP1 = ceil(double(EXP1) + d1 / 3);
    }
    else if(E2 < 500)
    {
        EXP2 = ceil(double(EXP2) + d1);
        EXP1 = ceil(double(EXP1) + d1 / 3);
        EXP2 = ceil(double(EXP2) + d2);
        EXP1 = ceil(double(EXP1) + d2 / 3);
    }
    else
    {
        EXP2 = ceil(double(EXP2) + d1);
        EXP1 = ceil(double(EXP1) + d1 / 3);
        EXP2 = ceil(double(EXP2) + d2);
        EXP1 = ceil(double(EXP1) + d2 / 3);
        EXP2 = ceil(double(EXP2) + d3);
        EXP1 = ceil(double(EXP1) + d3 / 3);
    }

    //The second period
    HP2 = ceil(double(HP2) - pow(E2,3) / pow(2,23));
    if(!(E2 % 2))
    {
        M2 = ceil(double(M2) + pow(E2,2) / 50);
    }
    Makesense_E(EXP1); Makesense_E(EXP2);
    Makesense_H(HP2);
    Makesense_M(M2);
    return EXP1 + EXP2 + HP2 + M2;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    if(E3 < 0 || E3 > 999) return -999;

    Makesense_H(HP1);
    Makesense_M(M1);
    //Initial sequences, variables
    int P1[] = {0, 1, 3, 5, 7, 9, 11, 13, 15, 17};
    int P2[] = {0, 2, 3, 5, 7, 11, 13, 17};
    int P3[21];
    for(int k = 1; k <= 20; k++)
    {
        P3[k] = k * k * 4;
    }
    int P4[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool flag;
    //Variable to identify whether the luggage is found ?
    int four = 0;

    //The first road
    flag = false;
    for(int k = 1; k <= 9; k++)
    {
        P1[k] = (P1[k] + E3) % 26 + 65;
        if(P1[k] == 80)
        {
            HP1 -= P1[k] * k * 2;
            EXP1 += (1000 - P1[k] * k) % 101;
            M1 = ceil(double(M1) - (double(k) * E3 / 9));
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        four++;
        M1 = ceil(double(M1) - (81.0 * E3 / 9));
    }
    Makesense_E(EXP1);
    Makesense_M(M1);
    Makesense_H(HP1);

    //The second road
    flag = false;
    int s,m;
    s = 0;
    for(int k = 1; k <= 7; k++)
    {
        P2[k] = (P2[k] + E3) % 26;
        s += P2[k];
    }
    m = ceil(double(s) / 7);
    for(int k = 1; k <= 7; k++)
    {
        P2[k] = (P2[k] + s + m) % 26 + 65;
        if(P2[k] == 80)
        {
            HP1 -= P2[k] * k * 2;
            EXP1 += (1000 - P2[k] * k) % 101;
            M1 = ceil(double(M1) - (double(k) * E3 / 9));
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        four++;
        M1 = ceil(double(M1) - (49.0 * E3 / 9));
    }
    Makesense_E(EXP1);
    Makesense_M(M1);
    Makesense_H(HP1);

    //The third road
    flag = false;
    int _max = -100000000;
    for(int k = 1; k <= 20; k++)
    {
        P3[k] = (P3[k] + E3 * E3) % 113;
        if(P3[k] > _max) _max = P3[k];
    }
    for(int k = 1; k <= 20; k++)
    {
        int id = 20 - k + 1;
        P3[id] = (int)(ceil(double(P3[id] + E3) / _max)) % 26 + 65;
        if(P3[id] == 80)
        {
            HP1 -= P3[id] * k * 3;
            EXP1 += (3500 - P3[id] * k) % 300;
            M1 = ceil(double(M1) - (double(k) * E3 / 9));
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        four++;
        M1 = ceil(double(M1) - (400.0 * E3 / 9));
    }
    Makesense_E(EXP1);
    Makesense_M(M1);
    Makesense_H(HP1);

    //The final road
    flag = false;
    int _min,idmin;
    _min = 100000000;
    idmin = 1;
    for(int k = 1; k <= 12; k++)
    {
        P4[k] = (int)(P4[k] + pow(ceil(double(E3) / 29),3)) % 9;
        if(P4[k] < _min)
        {
            idmin = k;
            _min = P4[k];
        }
    }
    for(int k = 1; k <= 12; k++)
    {
        int id = 12 - k + 1;
        P4[id] = (int)((P4[id] + E3) * ceil(double(_min) / idmin)) % 26 + 65;
        if(P4[id] == 80)
        {
            HP1 -= P4[id] * k * 4;
            EXP1 += (4500 - P4[id] * k) % 400;
            M1 = ceil(double(M1) - (double(k) * E3 / 9));
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        four++;
        M1 = ceil(double(M1) - (144.0 * E3 / 9));
    }
    Makesense_E(EXP1);
    Makesense_M(M1);
    Makesense_H(HP1);

    //Check check
    if(four == 4)
    {
        HP1 -= (59 * E3) % 900;
        EXP1 -= (79 * E3) % 300;
        Makesense_E(EXP1);
        Makesense_H(HP1);
        return -1;
    }
    else return HP1 + EXP1 + M1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
