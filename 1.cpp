#include <iostream>
#include <cstring>
using namespace std;
class hero{
private:
    int live;
    string name;
protected:
    int xp;
    double money;
public:
    static int count;
    hero(){
    this->live=5;
    this->xp=0;
    this->money=625;
    this->name="ursa";
    this->count++;
    }
    hero(int l,int x,double m,string n){
    this->live=l;
    this->xp=x;
    this->money=m;
    this->name=n;
    this->count++;
    }
    //distruktor
    ~hero(){
    this->name="abbadon";
    this->count--;
    }
    void getinfo (){
    cout << name << endl << live << endl << xp << endl << money << endl;

    }
};

int hero::count = 0;

int main(){
cout << "Count: " << hero::count << "\n";
hero h1;
cout << "Count: " << hero::count << "\n";
hero h2(100,50,800,"invoker");
h1.getinfo();
h2.getinfo();
cout << "Count: " << hero::count << "\n";
return 0;
}
