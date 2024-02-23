# Function: calculateWorkspaceBounds

## Description:

The calculateWorkspaceBounds function determines the upper and lower bounds of the workspace in space due to geometric constraints and servo limitations. It iterates through a range of joint angles and computes the corresponding end effector positions using forward kinematics. By aggregating these positions, the function identifies the maximum and minimum values of the workspace along the x, y, and z axes. The function systematically samples joint angles within a predefined range and computes the corresponding end effector positions using the forward kinematics function. By aggregating these positions, the function determines the maximum and minimum coordinates along the x, y, and z axes, effectively defining the bounds of the robot's workspace. The resolution parameter controls the granularity of the sampling process, affecting the accuracy of the computed workspace bounds.

### Parameters:

lengths (Type: LinkLengths): A struct containing the lengths of the robot's links, including a1, a2, and a3.

resolution (Type: int): An integer specifying the resolution of the sampling for joint angles.

### Returns:

bounds (Type: WorkspaceBounds): A struct representing the bounds of the workspace, including minX, maxX, minY, maxY, minZ, and maxZ.

## Example:
```cpp
LinkLengths lengths = {1.0, 0.8, 0.6}; // Example link lengths
int resolution = 100; // Example resolution
WorkspaceBounds bounds = calculateWorkspaceBounds(lengths, resolution);
// bounds.minX, bounds.maxX, bounds.minY, bounds.maxY, bounds.minZ, and bounds.maxZ now contain the computed workspace bounds
```