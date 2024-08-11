#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to define a segment
struct Segment {
    string name;
    int base;
    int limit;
};

// Function to check if the address is within the segment
bool isValidAddress(Segment& seg, int address) {
    return address >= seg.base && address < (seg.base + seg.limit);
}

// Function to simulate segmentation
void simulateSegmentation(vector<Segment>& segments, int address) {
    for (Segment& seg : segments) {
        if (isValidAddress(seg, address)) {
            cout << "Address " << address << " is in segment '" << seg.name << "'." << endl;
            cout << "Segment Base: " << seg.base << ", Limit: " << seg.limit << endl;
            return;
        }
    }
    cout << "Address " << address << " is outside of defined segments." << endl;
}

int main() {
    // Define segments
    vector<Segment> segments = {
        {"Code", 100, 300},
        {"Data", 400, 200},
        {"Stack", 700, 100}
    };

    // Display segments information
    cout << "Defined Segments:" << endl;
    for (const auto& seg : segments) {
        cout << "Segment Name: " << seg.name << ", Base: " << seg.base << ", Limit: " << seg.limit << endl;
    }
    cout << endl;

    // Simulate segmentation with various addresses
    int addressesToCheck[] = {150, 450, 750, 950};

    for (int address : addressesToCheck) {
        simulateSegmentation(segments, address);
        cout << endl;
    }

    return 0;
}
