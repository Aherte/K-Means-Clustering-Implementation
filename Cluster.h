/**
 * @file Cluster.h
 * @brief Header file for the Cluster class.
 */

#pragma once
#include "Point.h"

 /**
  * @brief The Cluster class represents a cluster of data points in a multi-dimensional space.
  */
class Cluster {
private:
    int clusterId; ///< ID of the cluster.
    vector<double> centroid; ///< Centroid of the cluster.
    vector<Point> points; ///< Vector containing the data points in the cluster.

public:
    /**
     * @brief Constructor for the Cluster class.
     * @param clusterId The ID of the cluster.
     * @param centroid The centroid of the cluster.
     */
    Cluster(int clusterId, Point centroid);

    /**
     * @brief Adds a data point to the cluster.
     * @param p The data point to be added.
     */
    void addPoint(Point p);

    /**
     * @brief Removes a data point from the cluster.
     * @param pointId The ID of the data point to be removed.
     * @return True if the data point is successfully removed, false otherwise.
     */
    bool removePoint(int pointId);

    /**
     * @brief Removes all data points from the cluster.
     */
    void removeAllPoints();

    /**
     * @brief Gets the ID of the cluster.
     * @return The ID of the cluster.
     */
    int getId();

    /**
     * @brief Gets a specific data point in the cluster.
     * @param pos The position of the data point in the vector.
     * @return The data point at the specified position.
     */
    Point getPoint(int pos);

    /**
     * @brief Gets the number of data points in the cluster.
     * @return The size of the cluster.
     */
    int getSize();

    /**
     * @brief Gets the value of the centroid at the specified position.
     * @param pos The position (dimension) for which to get the value.
     * @return The value of the centroid at the specified position.
     */
    double getCentroidByPos(int pos);

    /**
     * @brief Sets the value of the centroid at the specified position.
     * @param pos The position (dimension) for which to set the value.
     * @param val The value to set.
     */
    void setCentroidByPos(int pos, double val);
};
