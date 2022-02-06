#include <bits/stdc++.h>
#include "studyInPink.h"
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define REP(i,n) for(int i = 1; i <= n; i++)
#define REPN(i,n) for(int i = 0; i < n; i++)
int main()
{
    vector<int> cas;
    vector<int> res;
    vector<int> res1;
    ifstream ifs;
    ifs.open("StudyInPinkINP.txt");
    for(int i = 1; i <= 4000; i++)
    {
        int x;
        for(int j = 1; j <= 9; j++)
        {
            ifs >> x;
            cas.pb(x);
        }
    }
    ifs.close();
    ifs.open("StudyInPinkOUT.txt");
    FOR(i,1,4000)
    {
        int x;
        FOR(j,1,12) 
        {
            ifs >> x;
            res.pb(x);
        }
    }
    ifs.close();
    int id1,id2;
    id1 = 0; id2 = 0;
    REP(i,4000)
    {
        int hp1,hp2,exp1,exp2,m1,m2,e1,e2,e3;
        hp1 = cas[id1]; hp2 = cas[id1 + 1];
        exp1 = cas[id1 + 2]; exp2 = cas[id1 + 3];
        m1 = cas[id1 + 4]; m2 = cas[id1 + 5];
        e1 = cas[id1 + 6]; e2 = cas[id1 + 7]; e3 = cas[id1 + 8];
        /*cout << hp1 << " " << hp2 << endl;
        cout << exp1 << " " << exp2 << endl;
        cout << m1 << " " << m2 << endl;
        cout << e1 << " " << e2 << " " << e3 << endl;*/
        id1 += 9;
        int res1,res2,res3,res4,res5;
        bool flag = true;
        res1 = firstMeet(exp1, exp2, e1);
        res2 = exp1; res3 = exp2;
        if(res1 != res[id2] || res2 != res[id2 + 1] || res3 != res[id2 + 2]) flag = false;
        id2 += 3;
        res1 = investigateScene(exp1, exp2, hp2, m2, e2);
        res2 = exp1; res3 = exp2; res4 = hp2; res5 = m2;
        if(res1 != res[id2] || res2 != res[id2 + 1] || res3 != res[id2 + 2] || res4 != res[id2 + 3] || res5 != res[id2 + 4]) flag = false;
        id2 += 5;
        res1 = traceLuggage(hp1, exp1, m1, e3);
        res2 = hp1; res3 = exp1; res4 = m1;
        if(res1 != res[id2] || res2 != res[id2 + 1] || res3 != res[id2 + 2] || res4 != res[id2 + 3]) flag = false;
        id2 += 4;
        if(flag)
        {
            cout << "Congrats !! You have passed the #" << i << " testcase." << endl;
        }
        else
        {
            cout << "Wrong answer at testcase #" << i << endl;
        }
    }
}
