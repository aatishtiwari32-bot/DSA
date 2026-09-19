class Solution {
public:
    int find_distance2(int x1, int y1, int x2, int y2) {
        int dist = sqrt(
            (x2-x1)*(x2-x1) +
            (y2-y1)*(y2-y1)
        );
        return dist;
    }
    int find_distance1(int p1, int p2) {
        int distance = sqrt((p1-p2)*(p1-p2));
        return distance;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        int i;
        int xclose_coord = x1;
        int yclose_coord = y1;
        int xclose = find_distance1(xCenter, x1);
        int yclose = find_distance1(yCenter, y1);
        for(i = x1; i <= x2; i++) {
            int Xvar = find_distance1(i, xCenter);
            if(Xvar < xclose) {
                xclose = Xvar;
                xclose_coord = i;
            }
        }
        for(i = y1; i <= y2; i++) {
            int Yvar = find_distance1(i, yCenter);
            if(Yvar < yclose) {
                yclose = Yvar;
                yclose_coord = i;
            }
        }
        int final_dist = find_distance2(
            xCenter,
            yCenter,
            xclose_coord,
            yclose_coord
        );
        if(final_dist <= radius) {
            return true;
        }
        else {
            return false;
        }
    }
};