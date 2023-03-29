#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Triangle {

    double a, b, c;
    double Area() const {
        double s = (a + b + c) / 2;

        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    bool operator<(const Triangle& other) const {
        return Area() < other.Area();
    }

};

int main() {

    ifstream input("triangles.txt");

    if (!input) {
        cerr << " Failed to open input file " << endl;
        return 1;
    }

    vector<Triangle> triangles;
    double a, b, c;

    while (input >> a >> b >> c) {
        triangles.push_back({ a, b, c });
    }

    sort(triangles.begin(), triangles.end());

    double min_per = 6, max_per = 18;
    vector<Triangle> per_triangles;

    for (auto& t : triangles) {

        double p = t.a + t.b + t.c;

        if (p >= min_per && p <= max_per) {
            per_triangles.push_back(t);
        }
    }

    ofstream output("sorted_triangles.txt");

    if (!output) {
        cerr << " Failed to open output file " << endl;

        return 1;
    }

    for (auto& t : triangles) {
        output << t.a << " " << t.b << " " << t.c << endl;
    }

    ofstream perimeter_output("perimeter_triangles.txt");

    if (!perimeter_output) {
        cerr << " Failed to open perimeter output file " << endl;
        return 1;
    }

    for (auto& t : per_triangles) {
        perimeter_output << t.a << " " << t.b << " " << t.c << endl;
    }




    return 0;
}