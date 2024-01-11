/**
 * @file Point.h
 * @brief Header file for the Point class.
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "matplotlib.h"

using namespace std;
namespace plt = matplotlibcpp;

/**
 * @brief The Point class represents a data point in a multi-dimensional space.
 */
class Point {
public:
    /**
     * @brief Constructor for the Point class.
     * @param id The unique identifier for the data point.
     * @param line The string containing the values of the data point.
     */
    Point(int id, string line);

    /**
     * @brief Gets the number of dimensions in the data point.
     * @return The number of dimensions.
     */
    int getDimensions();

    /**
     * @brief Gets the cluster to which the data point belongs.
     * @return The ID of the cluster.
     */
    int getCluster();

    /**
     * @brief Gets the unique identifier of the data point.
     * @return The ID of the data point.
     */
    int getID();

    /**
     * @brief Sets the cluster to which the data point belongs.
     * @param val The ID of the cluster.
     */
    void setCluster(int val);

    /**
     * @brief Gets the value of the data point at the specified position.
     * @param pos The position (dimension) for which to get the value.
     * @return The value at the specified position.
     */
    double getVal(int pos);

private:
    int pointId; ///< Unique identifier for the data point.
    int clusterId; ///< ID of the cluster to which the data point belongs.
    int dimensions; ///< Number of dimensions in the data point.
    vector<double> values; ///< Vector containing the values of the data point.

    /**
     * @brief Converts a string containing values into a vector of doubles.
     * @param line The string containing the values.
     * @return Vector of doubles representing the values.
     */
    vector<double> lineToVec(const string& line);
};
