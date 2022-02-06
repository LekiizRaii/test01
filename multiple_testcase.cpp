#include "studyInPink.h"
using namespace std;
//==================
void solve(int id)
{
    int HP1 = -1, HP2 = -1;
    int EXP1 = -1, EXP2 = -1;
    int M1 = -1, M2 = -1;
    int E1 = -1, E2 = -1, E3 = -1;
    cin>>HP1>>HP2;
    cin>>EXP1>>EXP2;
    cin>>M1>>M2;
    cin>>E1>>E2>>E3;
    cout << firstMeet(EXP1, EXP2, E1) << endl;
    cout << EXP1 << " "<< EXP2 << endl;
    //Task 2
    //if(id == 15) cout << EXP1 << " "<< EXP2 << " " << HP2 << " " << M2 << " " << E2 << endl;
    cout << investigateScene(EXP1, EXP2, HP2, M2, E2)<< endl;
    cout << EXP1 << " "<< EXP2 << " " << HP2 << " " << M2 << endl;
    //Task 3
    //if(id == 26) cout << 'a' << HP1 << " "<< EXP1 << " " << M1 << " " << E3 << endl;
    cout << traceLuggage(HP1, EXP1, M1, E3)<< endl;
    cout << HP1 << " "<< EXP1 << " " << M1 << endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("test.out","w",stdout);
    int testcase;
    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        cout<<"Testcase #"<<i+1<<": \n";
        solve(i);
        cout<<"\n";
    }
    return 0;
}
