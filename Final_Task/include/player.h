class Player {
public:
    Player(int x, int y); // constructor that takes in initial x and y coordinates of player
    int getX();
    int getY();
    int getLifes();
    int getScore();
    void setX(int a);
    void setY(int a);
    void setLifes(int a);
    void setScore(int a);
private:
    int x, y, height; // player's coordinates and height
    int lifes = 3; // player's lifes
    int score; // player's score
};