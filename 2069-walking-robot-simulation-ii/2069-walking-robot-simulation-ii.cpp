class Robot {
    const int width, height;
    int x, y, dir;
    const vector<string> direction_name = {"East", "North", "West", "South"};
public:
    Robot(int _width, int _height) : width(_width), height(_height), x(0), y(0), dir(0) {}
    
    void step(int num) {
        int perimeter = 2 * (width + height) - 4;
        
        num %= perimeter;

        // Fix: treat full cycle properly
        if (num == 0) num = perimeter;

        while (num--) {
            if (dir == 0) { // East
                if (x + 1 < width) x++;
                else { dir = 1; y++; }
            }
            else if (dir == 1) { // North
                if (y + 1 < height) y++;
                else { dir = 2; x--; }
            }
            else if (dir == 2) { // West
                if (x - 1 >= 0) x--;
                else { dir = 3; y--; }
            }
            else { // South
                if (y - 1 >= 0) y--;
                else { dir = 0; x++; }
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return direction_name[dir]; }
};