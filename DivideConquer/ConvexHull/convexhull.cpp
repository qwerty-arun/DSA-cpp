#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// To find orientation of triplet (p, q, r)
// Returns:
// 0 --> colinear
// 1 --> clockwise
// 2 --> counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;             // colinear
    return (val > 0) ? 1 : 2;           // clock or counterclock wise
}

// Distance squared between two points
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// Global reference point for sorting
Point p0;

// Comparison function to sort points by polar angle with p0
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return o == 2;
}

// Main function to compute the convex hull
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull not possible

    // Step 1: Find the bottom-most point (or left-most if tie)
    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[minIndex].x)) {
            ymin = points[i].y;
            minIndex = i;
        }
    }

    // Place the bottom-most point at first position
    swap(points[0], points[minIndex]);
    p0 = points[0];

    // Step 2: Sort the remaining points based on polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Remove colinear points except the farthest one
    vector<Point> filtered;
    filtered.push_back(points[0]);
    for (int i = 1; i < n; ++i) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        filtered.push_back(points[i]);
    }

    if (filtered.size() < 3) return {};

    // Step 4: Use a stack to build the convex hull
    stack<Point> hull;
    hull.push(filtered[0]);
    hull.push(filtered[1]);
    hull.push(filtered[2]);

    for (int i = 3; i < filtered.size(); ++i) {
        while (hull.size() >= 2) {
            Point q = hull.top(); hull.pop();
            Point p = hull.top();
            if (orientation(p, q, filtered[i]) != 1) {
                hull.push(q);
                break;
            }
        }
        hull.push(filtered[i]);
    }

    // Step 5: Extract points from stack to vector
    vector<Point> result;
    while (!hull.empty()) {
        result.push_back(hull.top());
        hull.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

void printHull(const vector<Point>& hull) {
    cout << "Points in Convex Hull:\n";
    for (const auto& p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1},
        {2, 1}, {3, 0}, {0, 0}, {3, 3}
    };

    vector<Point> hull = convexHull(points);

    if (hull.empty()) {
        cout << "Convex hull not possible (less than 3 unique points).\n";
    } else {
        printHull(hull);
    }

    return 0;
}
