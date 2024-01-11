#pragma once
#include "kmeans.h"
/**
 * @brief Class representing features for a k-means clustering algorithm.
 */
class features
{
private:
    int K; /**< Number of clusters. */
    int iters; /**< Number of iterations for k-means algorithm. */
    int pointId; /**< ID of the point. */
    string output_dir; /**< Output directory for results. */
    string filename; /**< Input file name. */
    vector<Point> all_points; /**< Vector containing all data points. */
    string line; /**< String representation of a line. */
public:
        /**
     * @brief Constructor for the Features class.
     * @param file Input file name.
     * @param output Output directory for results.
     * @param k Number of clusters.
     * @param Iters Number of iterations for k-means algorithm.
     * @param ID ID of the point.
     * @param points Vector containing all data points.
     * @param ln String representation of a line.
     */
	features(const string& file = "", const string& output = "./",int k = 0, int Iters = 0, int ID = 0, const vector<Point>& points = vector<Point>(), const string& ln = "");
	void features_enter();
	void features_visulize();
	void readFromFile();
	void runfeatures();
};

