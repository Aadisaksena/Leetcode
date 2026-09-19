class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // If center is inside rectangle
        if (xCenter >= x1 && xCenter <= x2 &&
            yCenter >= y1 && yCenter <= y2)
            return true;

        int dx = 0, dy = 0;

        // Find closest vertical side
        if (xCenter < x1)
            dx = x1 - xCenter;
        else if (xCenter > x2)
            dx = xCenter - x2;

        // Find closest horizontal side
        if (yCenter < y1)
            dy = y1 - yCenter;
        else if (yCenter > y2)
            dy = yCenter - y2;

        // Distance from center to closest point of rectangle
        return dx * dx + dy * dy <= radius * radius;
    }
};