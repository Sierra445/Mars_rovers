# Mars Rover Simulator

## Description

The **Mars Rover Simulator** is a C++ program that simulates a rover moving on a 2D grid based on instructions from a file. The rover can move forward a specified distance and rotate clockwise or counterclockwise. It tracks its position `(x, y)` and orientation in degrees.

---

## Features

* Move forward in the current orientation.
* Rotate clockwise or counterclockwise.
* Print updated position and orientation after each instruction.
* Supports reading instructions from a text file.

---

## Instructions File Format

Instructions should be in a plain text file (`instructions.txt`) with one command per line:

1. **Move command**

```
move <distance>
```

Example:

```
move 10
```

2. **Turn command**

```
turn <clockwise|counterclockwise> <angle>
```

Example:

```
turn clockwise 90
turn counterclockwise 45
```

*Commands are case-insensitive for directions.*

---

## Example `instructions.txt`

```
move 10
turn clockwise 90
move 5
turn counterclockwise 45
move 7
```

---

## How to Compile and Run

```bash
g++ mars_rover.cpp -o mars_rover -lm
./mars_rover
```

**Explanation:**

* `-lm` links the math library for sine/cosine functions.
* Output will display the rover's updated position `(x, y)` and orientation in degrees after each command.

---

## Output Example

```
Moved 10 meters to (0, 10) facing 0 degrees.
Turned clockwise to orientation 90 degrees.
Moved 5 meters to (5, 10) facing 90 degrees.
Turned counterclockwise to orientation 45 degrees.
Moved 7 meters to (9.95, 14.95) facing 45 degrees.
```

---

## Notes

* Orientation is normalized between `0` and `360` degrees.
* Uses double precision for coordinates and angles.
* Empty lines in the instructions file are ignored.

