enum class PowerUpVar{health, shots};

class PowerUp{
public:
    PowerUp(int x, int y, PowerUpVar var); // constructor that takes in the variant and the initial x and y coordinates of the power up
    int getX();
    int getY();
    bool getActive();
    PowerUpVar getVar();
    void setX(int a);
    void setY(int a);
    void setActive(bool a);

private:
    int x, y; // coordinates of the power up
    bool active = true; //  bool wether or not the upgrade is active
    PowerUpVar var; // Variant of the power up
};