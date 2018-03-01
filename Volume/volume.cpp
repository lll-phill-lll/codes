#include <stdexcept>
constexpr double PI = 3.1415926;

struct Point3D {
    double X, Y, Z;
};

class Figure3D {
    Point3D center;
public:
    Figure3D(const Point3D& c): center(c) {
    }
    const Point3D& Center() const {
        return center;
    }
    virtual double Volume() const = 0;
    virtual ~Figure3D() {}
};

class Ball: public Figure3D {
 private:
     double r_;
 public:
    Ball(const Point3D& mid, double r):Figure3D(mid) {
    if (r < 0) {
        throw std::domain_error("Length must be non-negative");
    }
        r_ = r;
    }
    double Volume() const override {
        return  PI * (4. / 3) * r_ * r_ * r_;
    }
};

class Cuboid: public Figure3D {
 private:
    double x_, y_, z_;
 public:
    Cuboid(const Point3D& mid, double x, double y, double z):Figure3D(mid) {
    if ((x < 0) || (y < 0) || (z < 0)) {
        throw std::domain_error("Length must be non-negative");
    }
    x_ = x;
    y_ = y;
    z_ = z;
    }
    double Volume() const override {
        return x_ * y_ * z_;
    }
};
