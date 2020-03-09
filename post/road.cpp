#include <iostream>
using namespace std;
class RoadDisplay {
public:
    void draw() { std::cout << "기본 도로 표시" << std::endl; }
}; 

class RoadDisplayWithLane : public RoadDisplay {
public:
    void draw() {
        RoadDisplay::draw();
        drawLane();
    }
    void drawLane() { std::cout << "차선 표시" << std::endl; }
};

int main() {
    RoadDisplay* road = new RoadDisplay();
    road->draw();

    RoadDisplayWithLane* roadWithLane = new RoadDisplayWithLane();
    roadWithLane->draw();

    return 0;
}
