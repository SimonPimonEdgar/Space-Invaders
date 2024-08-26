class Shot {
public:
    Shot(int x, int y, bool dir); // contructor that takes in the direction and the initial x and y coordinates of the shot
    int getX();
    int getY();
    bool getDir();
    bool getActive();
    void setX(int a);
    void setY(int a);
    void setActive(bool a);

private:
    int x, y; // coordinates of the shot
    bool dir; // direction of the shot (Upwards = True, Downwards = False)
    bool active = true; // bool wether or not a shot should not be deleted
};