#include "Vector2D.h"

Vector2D::Vector2D() {

}

Vector2D::Vector2D(double x, double y) : x(x), y(y) {

}

Vector2D rot90(Vector2D v) {
    return Vector2D(-v.y, v.x);
}

Vector2D operator*(double x, Vector2D v) {
    return Vector2D(v.x * x, v.y * x);
}

Vector2D operator*(Vector2D v, double x) {
    return Vector2D(v.x * x, v.y * x);
}

Vector2D operator+(Vector2D a, Vector2D b) {
    return Vector2D(a.x + b.x, a.y + b.y);
}

double operator*(Vector2D a, Vector2D b) {
    return a.x * b.x + a.y * b.y;
}

Vector2D norm(Vector2D x) {
    return x * (1 / sqrt(x * x));
}