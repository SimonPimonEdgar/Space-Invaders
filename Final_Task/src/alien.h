class Alien {
public:
    Alien(int var, int x, int y); // constructor that takes in the variant and the initial x and y coordinates of the alien
    int getVar();
    int getX();
    int getY();
    int getH();
    bool getDead();
    void setX(int a);
    void setY(int a);
    void setDead(bool a);

private:
    int x, y; // coordinates of the alien
    bool dead = false; // bool wether or not the alien got hit
    int var; // variant of the alien
};