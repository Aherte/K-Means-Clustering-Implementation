#pragma once

#include "Cluster.h"

class kmeans {
private:
    int K; ///< Number of clusters.
    int iters; ///< Maximum number of iterations for the k-means algorithm.
    int dimensions; ///< Number of dimensions in the data.
    int total_points; ///< Total number of data points.
    string output_dir; ///< Output directory for result files.
    vector<Cluster> clusters; ///< Vector to store clusters.

public:
    /**
     * @brief Constructor for the kmeans class.
     * @param K Number of clusters.
     * @param iterations Maximum number of iterations for the k-means algorithm.
     * @param output_dir Output directory for result files.
     */
    kmeans(int K, int iterations, string output_dir);

    /**
     * @brief Clears all points from each cluster.
     */
    void clearClusters();

    /**
     * @brief Gets the ID of the cluster to which a point belongs.
     * @param point The point to find the nearest cluster for.
     * @return The ID of the nearest cluster.
     */
    int getNearestClusterId(Point point);

    /**
     * @brief Runs the k-means clustering algorithm.
     * @param all_points Vector containing all data points to be clustered.
     */
    void run(vector<Point>& all_points);

    /**
     * @brief Writes the results of the clustering to output files.
     * @param all_points Vector containing all data points after clustering.
     */
    void writeResultsToFile(vector<Point>& all_points);

    /**
     * @brief Gets a reference to a cluster by its index.
     * @param index The index of the cluster.
     * @return A reference to the specified cluster.
     */
    Cluster& getCluster(int index);
};
