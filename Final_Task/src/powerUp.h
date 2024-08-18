enum class PowerUpVar{one};

class PowerUp{
public:
    PowerUp(int x, int y, PowerUpVar var); // constructor that takes in the variant and the initial x and y coordinates of the power up
    int getX();
    int getY();
    int getVar();
    void setX();
    void setY();

private:
    int x, y; // coordinates of the power up
    PowerUpVar var; // Variant of the power up
};