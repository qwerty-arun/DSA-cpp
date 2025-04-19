#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <float.h>

using namespace std;

struct Point {
    double x, y;
};

// Comparison function for sorting by X
bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// Comparison function for sorting by Y
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// Function to calculate distance between two points
double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

// A brute-force method to return the smallest distance for small n (n <= 3)
double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

// Find the closest distance in the strip of points
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

// Recursive function using Divide and Conquer
double closestUtil(vector<Point>& Px, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(Px, left, right);
    }

    int mid = (left + right) / 2;
    Point midPoint = Px[mid];

    double dl = closestUtil(Px, left, mid);
    double dr = closestUtil(Px, mid, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (fabs(Px[i].x - midPoint.x) < d) {
            strip.push_back(Px[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

// Wrapper function
double closestPair(vector<Point>& points) {
    vector<Point> Px = points;
    sort(Px.begin(), Px.end(), compareX);
    return closestUtil(Px, 0, Px.size());
}

int main() {
    vector<Point> points = {
        {2.1, 3.5},
        {12.3, 30.1},
        {40.0, 50.0},
        {5.2, 1.3},
        {12.0, 10.3},
        {3.0, 4.0}
    };

    double minDist = closestPair(points);
    cout << "The smallest distance is: " << minDist << endl;

    return 0;
}
