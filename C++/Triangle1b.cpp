#include <iostream>
#include <string>
#define ROW 0
#define COLUMN1 1
#define COLUMN2 2
#define MAX_ROW 5
#include<algorithm>
using namespace std;

class Point
{
    public:
    
        Point()
        {
            x = 0;
            y = 0;
        }
        int x, y;
        
        bool distance(Point p1)
        {
            int result = abs(x - p1.x) + abs(y-p1.y);
            if(result == 10)
            {
                return false;
            }
            else if (result == 20)
            {
                return true;
            }
            else
                return false;
        }
        
        
};
class Triangle
{
    public:
    
    Triangle(){
    }
    Point points[3];

    
     

    
    bool isValidTriangle()
    {
        int point1, point2, point3;
        if (points[0].distance(points[1]))
        {
            point1 = 0;
            point2 = 1;
            point3 = 2;
        }
        else if(points[0].distance(points[2]))
        {
            point1 = 0;
            point2 = 2;
            point3 = 1;
        }
        else if(points[1].distance(points[2]))
        {
            point1 = 1;
            point2 = 2;
            point3 = 0;
        }
        else
        {
            return false;
        }
        int m = max({points[point1].x , points[point1].y, points[point2].x, points[point2].y});
        int trNo;
        char trName;
        if (isUpperTriangle(point3, m))
        {
            trNo = points[point3].x/10 * 2;
            trName = MAX_ROW - points[point3].y/10 + 'A' + 1;
        }
        else 
        {
            trNo = (points[point3].x/10 * 2) + 1;
            trName = MAX_ROW - points[point3].y/10 + 'A';
        }
        cout<<trName<<trNo;
        return true;
    }
   
    bool isUpperTriangle(int point3, int max)
    {
        if (max == points[point3].x || max == points[point3].y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    
    Triangle t;
    cout<<"Enter first point (x1 y1)";
    cin>>t.points[0].x>>t.points[0].y;
    cout<<"Enter second point (x2 y2)";
    cin>>t.points[1].x>>t.points[1].y;
    cout<<"Enter third point (x3 y3)";
    cin>>t.points[2].x>>t.points[2].y;
    // t.points[0].x = 20;
    // t.points[0].y = 20;
    // t.points[1].x = 30;
    // t.points[1].y = 20;
    // t.points[2].x = 20;
    // t.points[2].y = 30;

    
    // t.points[0].x = 10;
    // t.points[0].y = 10;
    // t.points[1].x = 10;
    // t.points[1].y = 0;
    // t.points[2].x = 0;
    // t.points[2].y = 10;
    t.isValidTriangle();

    return 0;
}





