#ifndef VEC2_H
#define VEC2_H

class Vec2 {
    public:
        // Constructors
        Vec2() : x(0.0f), y(0.0f) {}
        Vec2(float x, float y) : x(x), y(y) {}

        float x;
        float y;
};

#endif