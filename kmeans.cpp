
#include "kmeans.h"

kmeans::kmeans(int K, int iterations, string output_dir)
{
    this->K = K;
    this->iters = iterations;
    this->output_dir = output_dir;
}

void kmeans::clearClusters()
{
    for (int i = 0; i < K; i++)
    {
        clusters[i].removeAllPoints();
    }
}

int kmeans::getNearestClusterId(Point point)
{
    double sum = 0.0, min_dist;
    int NearestClusterId;
    if (dimensions == 1) {
        min_dist = abs(clusters[0].getCentroidByPos(0) - point.getVal(0));
    }
    else
    {
        for (int i = 0; i < dimensions; i++)
        {
            sum += pow(clusters[0].getCentroidByPos(i) - point.getVal(i), 2.0);
        }
        min_dist = sqrt(sum);
    }
    NearestClusterId = clusters[0].getId();

    for (int i = 1; i < K; i++)
    {
        double dist;
        sum = 0.0;

        if (dimensions == 1) {
            dist = abs(clusters[i].getCentroidByPos(0) - point.getVal(0));
        }
        else {
            for (int j = 0; j < dimensions; j++)
            {
                sum += pow(clusters[i].getCentroidByPos(j) - point.getVal(j), 2.0);
            }

            dist = sqrt(sum);
        }
        if (dist < min_dist)
        {
            min_dist = dist;
            NearestClusterId = clusters[i].getId();
        }
    }

    return NearestClusterId;
}

void kmeans::run(vector<Point>& all_points)
{
    total_points = all_points.size();
    dimensions = all_points[0].getDimensions();

    vector<int> used_pointIds;

    for (int i = 1; i <= K; i++)
    {
        while (true)
        {
            int index = rand() % total_points;

            if (find(used_pointIds.begin(), used_pointIds.end(), index) ==
                used_pointIds.end())
            {
                used_pointIds.push_back(index);
                all_points[index].setCluster(i);
                Cluster cluster(i, all_points[index]);
                clusters.push_back(cluster);
                break;
            }
        }
    }
    cout << "Clusters initialized = " << clusters.size() << endl
        << endl;

    cout << "Running K-Means Clustering.." << endl;

    int iter = 1;
    while (true)
    {
        cout << "Iter - " << iter << "/" << iters << endl;
        bool done = true;

#pragma omp parallel for reduction(&&: done) num_threads(16)
        for (int i = 0; i < total_points; i++)
        {
            int currentClusterId = all_points[i].getCluster();
            int nearestClusterId = getNearestClusterId(all_points[i]);

            if (currentClusterId != nearestClusterId)
            {
                all_points[i].setCluster(nearestClusterId);
                done = false;
            }
        }

        clearClusters();

        for (int i = 0; i < total_points; i++)
        {
            clusters[all_points[i].getCluster() - 1].addPoint(all_points[i]);
        }

        for (int i = 0; i < K; i++)
        {
            int ClusterSize = clusters[i].getSize();

            for (int j = 0; j < dimensions; j++)
            {
                double sum = 0.0;
                if (ClusterSize > 0)
                {
#pragma omp parallel for reduction(+: sum) num_threads(16)
                    for (int p = 0; p < ClusterSize; p++)
                    {
                        sum += clusters[i].getPoint(p).getVal(j);
                    }
                    clusters[i].setCentroidByPos(j, sum / ClusterSize);
                }
            }
        }

        if (done || iter >= iters)
        {
            cout << "Clustering completed in iteration : " << iter << endl
                << endl;
            break;
        }
        iter++;
    }

    ofstream pointsFile;
    pointsFile.open(output_dir + "/" + to_string(K) + "-points.txt", ios::out);

    for (int i = 0; i < total_points; i++)
    {
        pointsFile << all_points[i].getCluster() << endl;
    }

    pointsFile.close();

    ofstream outfile;
    outfile.open(output_dir + "/" + to_string(K) + "-clusters.txt");
    if (outfile.is_open())
    {
        for (int i = 0; i < K; i++)
        {
            cout << "Cluster " << clusters[i].getId() << " centroid : ";
            for (int j = 0; j < dimensions; j++)
            {
                cout << clusters[i].getCentroidByPos(j) << " ";   
                outfile << clusters[i].getCentroidByPos(j) << " "; 
            }
            cout << endl;
            outfile << endl;
        }
        outfile.close();
    }
    else
    {
        cout << "Error: Unable to write to clusters.txt";
    }
}

Cluster& kmeans::getCluster(int index)
{
    return clusters[index];
}


