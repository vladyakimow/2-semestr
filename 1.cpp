#include <iostream>
#include <cstring>
using namespace std;
class hero{
private:
    int live;
    int xp;
    double money;
    string name;
public:
    hero(){
    live=5;
    xp=0;
    money=625;
    name="ursa";
    }
    hero(int l,int x,double m,string n){
    live=l;
    xp=x;
    money=m;
    name=n;
    }    
    //distruktor
    ~hero(){
    name="abbadon";
    }
    void getinfo (){
    cout << name << endl << live << endl << xp << endl << money << endl; 
    }
};

int main(){
hero h1;
hero h2(100,50,800,"invoker");
h1.getinfo();
h2.getinfo();
return 0;
}
