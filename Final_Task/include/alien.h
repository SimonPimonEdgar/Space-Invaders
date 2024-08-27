enum class AlienVar {Normal, Tank, Elite};


class Alien {
public:
    Alien(AlienVar var, int x, int y); // constructor that takes in the variant and the initial x and y coordinates of the alien
    AlienVar getVar();
    int getX();
    int getY();
    int getLifes();
    void setX(int a);
    void setY(int a);
    void setLifes(int a);

private:
    int x, y; // coordinates of the alien
    int lifes; // bool wether or not the alien got hit
    AlienVar var; // variant of the alien
};