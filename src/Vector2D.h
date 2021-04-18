#pragma once

#include "headers.h"


class Vector2D {
public:
    Vector2D();

    Vector2D(double x, double y);

    double x, y;
};

Vector2D rot90(Vector2D v); // rotates vector 90 degrees anticlockwise

Vector2D operator*(double x, Vector2D v);

Vector2D operator*(Vector2D v, double x);

Vector2D operator+(Vector2D a, Vector2D b);

double operator*(Vector2D a, Vector2D b);

Vector2D norm(Vector2D x);
