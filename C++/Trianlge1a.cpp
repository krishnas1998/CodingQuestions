#include <iostream>
#include <string>
#define ROW 0
#define COLUMN1 1
#define COLUMN2 2
#define MAX_ROW 5

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
        
        string getPoints()
        {
            return "(" +  to_string(x) + "," + to_string(y) + ")";
        }
};

class Triangle
{
    public:
    
    Triangle(){
    }
    Point points[3];
    
    void printCoordinates()
    {
        cout<<" coordinates - "<<points[0].getPoints()<<","<<points[1].getPoints()<<","<<points[2].getPoints();
    }
};
Triangle printUpperTriangleCoordinate(int rowIndex, int columnIndex);
Triangle printLowerTriangleCoordinate(int rowIndex, int columnIndex);
int main()
{
    string triangle = "E6";
    char rowChar = triangle.at(ROW);
    int rowAscii = (int)triangle.at(ROW);
    int rowIndex, columnIndex;
    bool isLowerTriangle;
    Triangle t;
    if (rowAscii >= 'A' and rowAscii <= ('A' + MAX_ROW))
    {
        rowIndex = MAX_ROW - (rowAscii - 'A');
    }
    else
    {
        cout<<"Invalid input";
        return 0;
    }
    
    int triangleLength = triangle.length();
    if (triangleLength == 2)
    {
        columnIndex = triangle.at(COLUMN1) - '0';
        
    }
    else if (triangleLength == 3)
    {
        columnIndex = (triangle.at(COLUMN1) - '0') * 10 + (triangle.at(COLUMN2) - '0');
    }
    else
    {
        cout<<"Invalid input";
        return 0;
    }
    
    
    isLowerTriangle = columnIndex % 2;
    
    if (isLowerTriangle)
    {
        t = printLowerTriangleCoordinate(rowIndex,columnIndex); 
    }
    else
    {
        t = printUpperTriangleCoordinate(rowIndex,columnIndex); 
        
    }
    cout<<"Triangle "<<triangle;
    t.printCoordinates();

    return 0;
}

Triangle printUpperTriangleCoordinate(int rowIndex, int columnIndex)
{
    Triangle triangle;
    //cout<<"rowIndex "<<rowIndex<<" columnIndex "<<columnIndex<<endl;
    triangle.points[0].y = rowIndex * 10;
    triangle.points[1].y = triangle.points[2].y = (rowIndex+1) * 10;
    triangle.points[0].x = triangle.points[1].x = (columnIndex/2) * 10;
    triangle.points[2].x = ((columnIndex-1)/2) * 10;
    return triangle;
}

Triangle printLowerTriangleCoordinate(int rowIndex, int columnIndex)
{
    Triangle triangle;
    //cout<<"rowIndex "<<rowIndex<<" columnIndex "<<columnIndex<<endl;
    triangle.points[0].y = triangle.points[1].y = rowIndex * 10;
    triangle.points[2].y = (rowIndex+1) * 10;
    triangle.points[0].x = ((columnIndex+1)/2) * 10;
    triangle.points[1].x = triangle.points[2].x = ((columnIndex-1)/2) * 10;
    return triangle;
}