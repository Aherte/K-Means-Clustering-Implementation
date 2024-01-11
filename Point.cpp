#include "Point.h"

Point::Point(int id, string line)
{
    pointId = id;
    values = lineToVec(line);
    dimensions = values.size();
    clusterId = 0; 
}

vector<double> Point::lineToVec(const string& line)
{
    vector<double> values;
    string tmp = "";

    for (int i = 0; i < (int)line.length(); i++)
    {
        if ((48 <= int(line[i]) && int(line[i]) <= 57) || line[i] == '.' || line[i] == '+' || line[i] == '-' || line[i] == 'e')
        {
            tmp += line[i];
        }
        else if (tmp.length() > 0)
        {
            values.push_back(stod(tmp));
            tmp = "";
        }
    }

    if (tmp.length() > 0)
    {
        values.push_back(stod(tmp));
        tmp = "";
    }

    return values; 
}

int Point::getDimensions()
{
    return dimensions;
}

int Point::getCluster()
{
    return clusterId;
}

int Point::getID()
{
    return pointId;
}

void Point::setCluster(int val)
{
    clusterId = val;
}

double Point::getVal(int pos)
{
    return values[pos];
}