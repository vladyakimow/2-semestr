#include <iostream>
#include <cstring>
using namespace std;

class entity {
private:
    int live;
    string name;
protected:
    int xp;
    double money;
public:
    virtual void setname() = 0;
};

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
    class inventory {
        string inv[20];
        void settocell(int i, string item) {
            inv[i] = item;
        }
        string getcell(int i) {
            return inv[i];
        }
    };
    void setname(string s) {
        name = s;
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
    hero& operator+(int lives) {
        live += lives;
    }
    hero& operator++() {
        live++;
    }
    hero& operator--() {
        live--;
    }
    hero& operator+(double mon) {
        money += mon;
    }
    hero& operator=(string newname) {
        name = newname;
    }
    friend ostream& operator<< (ostream& out, const hero& h);
    friend istream& operator>> (istream& in, hero& hero);
    friend class enemy;
};

class enemy : hero {
private:
    static int countenemy;
public:
    int difficulty;
    enemy (int l,int x,double m,string n, int d){
        hero(l, x, m, n);
        countenemy++;
        this->difficulty = d;
    }
    void killhero(hero& h) {
        h.live = 0;
        h.xp = 0;
        h.money = 0;
    }
private:
    int getdifficulty() {
        return difficulty;
    }
};

ostream& operator<< (ostream& out, const hero& h) {
    cout << h.name << endl << h.live << endl << h.xp << endl << h.money << endl;
    return out;
}

istream& operator>> (istream& in, hero& h) {
    class input {
    public:
        string heroname;
        hero& h = h;
        void sethero() {
            h = hero(0, 0, 0.0, heroname);
        }
    };
    input inp;
    cin >> inp.heroname;
    inp.sethero();
    return in;
}

int hero::count = 0;
int enemy::countenemy = 0;

int main(){
cout << "Count: " << hero::count << "\n";
cout << "Count: " << hero::count << "\n";
hero h1;
cin >> h1;
hero h2(100,50,800,"invoker");
h1.getinfo();
h2.getinfo();
cout << "Count: " << hero::count << "\n";
return 0;
}
