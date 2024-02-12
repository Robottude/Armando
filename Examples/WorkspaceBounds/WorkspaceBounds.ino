#include "Armed.h"

// define the variables to hold link lengths, joint angles, and end effector position
LinkLengths Lengths;
JointAngles Angles;
EndEffectorPosition Position;

void setup() {
    Serial.begin(9600);

    // define link lengths
    LinkLengths lengths = {10.0, 10.0, 10.0}; // Example link lengths (replace with your values)

    // define resolution for workspace calculation
    int resolution = 100; // Example resolution (adjust as needed)

    // calculate workspace bounds
    WorkspaceBounds bounds = calculateWorkspaceBounds(lengths, resolution);

    // print the calculated workspace bounds
    Serial.println("Workspace Bounds:");
    Serial.print("Min X: ");
    Serial.println(bounds.minX);
    Serial.print("Max X: ");
    Serial.println(bounds.maxX);
    Serial.print("Min Y: ");
    Serial.println(bounds.minY);
    Serial.print("Max Y: ");
    Serial.println(bounds.maxY);
    Serial.print("Min Z: ");
    Serial.println(bounds.minZ);
    Serial.print("Max Z: ");
    Serial.println(bounds.maxZ);
}
void loop() {
    // nothing to loop
}
