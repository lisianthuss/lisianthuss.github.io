#include <iostream>
using namespace std;

class Display {
public:
    Display() {}
    virtual ~Display() {}
    virtual void draw() = 0;
};

class RoadDisplay : public Display {
public:
    void draw() { std::cout << "기본 도로 표시" << std::endl; }
};

class DisplayDecorator : public Display {
public:
    DisplayDecorator() {}
    virtual ~DisplayDecorator() {}

    DisplayDecorator(Display* display) { decoratedDisplay = display; }
    void draw() { decoratedDisplay->draw(); }
private:
    Display* decoratedDisplay;
};

class LaneDecorator : public DisplayDecorator {
public:
    LaneDecorator() {}
    virtual ~LaneDecorator() {}
    LaneDecorator(Display* decoratedDisplay): DisplayDecorator(decoratedDisplay) {}

    void draw() {
        DisplayDecorator::draw();
        drawLane();
    }
    void drawLane() { std::cout << "\t차선 표시" << std::endl; }
};

class TrafficDecorator : public DisplayDecorator {
public:
    TrafficDecorator() {}
    virtual ~TrafficDecorator() {}
    TrafficDecorator(Display* decoratedDisplay):DisplayDecorator(decoratedDisplay) {}

    void draw() {
        DisplayDecorator::draw();
        drawLane();
    }
    void drawLane() { std::cout << "\t교통량 표시" << std::endl; }
};
int main() {
    Display* road = new RoadDisplay();
    road->draw();

    Display* roadWithLane = new LaneDecorator(new RoadDisplay());
    roadWithLane->draw();

    Display* roadWithTraffic = new TrafficDecorator(new RoadDisplay());
    roadWithTraffic->draw();

    Display* roadWithLaneAndTraffic = new TrafficDecorator(new LaneDecorator(new RoadDisplay()));
    roadWithLaneAndTraffic->draw();

    delete roadWithLaneAndTraffic;
    delete roadWithTraffic;
    delete roadWithLane;
    delete road;

    return 0;
}

