#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Global variables
double x = 0;
double y = 0;
double orientation = 0; // in degrees

// Convert degrees to radians
double degrees_to_radian(double degree) {
    return degree * M_PI / 180.0;
}

// Calculate change in x based on orientation
double change_in_x(double distance, double orientation) {
    return distance * sin(degrees_to_radian(orientation));
}

// Calculate change in y based on orientation
double change_in_y(double distance, double orientation) {
    return distance * cos(degrees_to_radian(orientation));
}

// Update orientation clockwise
double update_orientation_clockwise(double turn_angle) {
    orientation = fmod((orientation + turn_angle), 360.0);
    return orientation;
}

// Update orientation counterclockwise
double update_orientation_counterclockwise(double turn_angle) {
    orientation = fmod((orientation - turn_angle + 360.0), 360.0); // +360 to handle negative
    return orientation;
}

// Process Mars rover instructions
void mars_rovers(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string action;
        double value;
        string direction;
        iss >> action;

        if (action == "move") {
            iss >> value;
            x += change_in_x(value, orientation);
            y += change_in_y(value, orientation);
            cout << "Moved " << value << " meters to (" << x << ", " << y << ") facing " << orientation << " degrees." << endl;
        }
        else if (action == "turn") {
            iss >> direction >> value;
            if (direction == "clockwise") {
                update_orientation_clockwise(value);
            } else if (direction == "counterclockwise") {
                update_orientation_counterclockwise(value);
            }
            cout << "Turned " << direction << " to orientation " << orientation << " degrees." << endl;
        }
    }

    file.close();
}

int main() {
    mars_rovers("instructions.txt");
    return 0;
}