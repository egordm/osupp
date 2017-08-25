//
// Created by egordm on 24-8-2017.
//

#ifndef OSUPP_MATHS_H
#define OSUPP_MATHS_H

#include <cmath>
#include <vector>
#include <ostream>

#define VECTOR_NORMALIZE_EPSILON 0.000001f

struct Coordinate {
    float x;
    float y;

    Coordinate() : x(0), y(0) {};

    Coordinate(float x, float y) : x(x), y(y) {};

    void zero();

    void set(float x, float y);

    float length() const;                         //
    float distance(const Coordinate &vec) const;     // distance between two vectors
    Coordinate &normalize();                            //
    float dot(const Coordinate &vec) const;          // dot product
    bool equal(const Coordinate &vec, float e) const; // compare with epsilon

    Coordinate operator-() const;                      // unary operator (negate)
    Coordinate operator+(const Coordinate &rhs) const;    // add rhs
    Coordinate operator-(const Coordinate &rhs) const;    // subtract rhs
    Coordinate &operator+=(const Coordinate &rhs);         // add rhs and update this object
    Coordinate &operator-=(const Coordinate &rhs);         // subtract rhs and update this object
    Coordinate operator*(const float scale) const;     // scale
    Coordinate operator*(const Coordinate &rhs) const;    // multiply each element
    Coordinate &operator*=(const float scale);          // scale and update this object
    Coordinate &operator*=(const Coordinate &rhs);         // multiply each element and update this object
    Coordinate operator/(const float scale) const;     // inverse scale
    Coordinate &operator/=(const float scale);          // scale and update this object
    bool operator==(const Coordinate &rhs) const;   // exact compare, no epsilon
    bool operator!=(const Coordinate &rhs) const;   // exact compare, no epsilon
    bool operator<(const Coordinate &rhs) const;    // comparison for sort
    float operator[](int index) const;            // subscript operator v[0], v[1]
    float &operator[](int index);                  // subscript operator v[0], v[1]

    friend Coordinate operator*(const float a, const Coordinate vec);

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &vec);
};

#define Coords std::vector<Coordinate>

namespace maths {
    bool isClose(float a, float b);

    Coords bezierCurve(Coords controlPoints);

    Coords perfectCurve(Coordinate a, Coordinate b, Coordinate c);

    Coordinate catmullPoint(Coordinate p1, Coordinate p2, Coordinate p3, Coordinate p4, float t);

    Coords catmullCurve(Coordinate p1, Coordinate p2, Coordinate p3, Coordinate p4, float interval);

    Coords catmullChain(Coords points, float interval);
}

#endif //OSUPP_MATHS_H
