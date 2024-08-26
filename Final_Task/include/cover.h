class Cover{
public:
    Cover(int x, int y); //constructor that takes the x and y coordinate of the cover object
    int getX();
    int getY();
    int getLifes();
    void setX(int a);
    void setY(int a);
    void setLifes(int a);
private:
    int x,y; // x and y coordinate of the left tile from the cover
    int life = 5;
    bool dead = false;
};