class Solution {
public:    
    double find_side(double x1, double y1, double x2, double y2){
        double side = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        return side;
    }
    
    double find_area(double a, double b, double c){
        double s = (a + b + c) / 2;
        double area = s * (s - a) * (s - b) * (s - c);
        return sqrt(area);
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxi = 0;
        for(int i = 0; i < n; i++){
            double x1 = points[i][0];
            double y1 = points[i][1];
            for(int j = i + 1; j < n; j++){
                double x2 = points[j][0];
                double y2 = points[j][1];
                for(int k = j + 1; k < n; k++){
                    double x3 = points[k][0];
                    double y3 = points[k][1];
                    double a = find_side(x1, y1, x2, y2);
                    double b = find_side(x1, y1, x3, y3);
                    double c = find_side(x2, y2, x3, y3);
                    double area = find_area(a, b, c);           
                    maxi = max(maxi, area);
                }
            }
        }      
        return maxi;
    }
};