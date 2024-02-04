# K-Means-Clustering-Implementation
This project centers around implementing the K-means clustering method through a carefully crafted class hierarchy. Drawing upon existing K-means implementations or referring to https://en.wikipedia.org/wiki/K-means_clustering, the design aims for an efficient and versatile structure.

## Output Images
![Ekran görüntüsü 2024-01-12 235917](https://github.com/Aherte/K-Means-Clustering-Implementation/assets/55800601/a746ee14-15fe-4561-83e4-2aaec591fdb4)

![Ekran görüntüsü 2024-01-12 235959](https://github.com/Aherte/K-Means-Clustering-Implementation/assets/55800601/7897a988-9cb0-42f4-ad45-5a7a39120075)

![Ekran görüntüsü 2024-01-13 000031](https://github.com/Aherte/K-Means-Clustering-Implementation/assets/55800601/5f780419-9982-4f23-8327-8ddf5e5c681f)

![Ekran görüntüsü 2024-01-13 000046](https://github.com/Aherte/K-Means-Clustering-Implementation/assets/55800601/d8d7f8df-d01d-440c-a86a-2c763324f582)

1. Point Class 
The `Point` class represents the characteristics of data points within clusters. Each point 
includes an identity (ID), coordinate values, and information about the cluster it belongs to. 
Additionally, it incorporates a conversion function that transforms input lines into numerical 
values. This class serves as the representation of input data for the k-means algorithm.
2. kmeans Class 
The `kmeans` class implements the k-means clustering algorithm. By clustering given data 
points into a specified number of clusters (K), it updates the cluster centers and iterates this 
process for a given number of iterations. The `kmeans` class executes the clustering process 
and, in addition, saves the results to a file, updating the cluster centers as part of the k-means 
algorithm.
3. Cluster Class 
The `Cluster` class forms the fundamental structure of clusters. Each cluster contains a cluster 
center, a cluster ID, and the points belonging to that cluster. It also includes functions for 
updating cluster centers during the clustering process, as well as adding and removing points. 
This class is responsible for carrying out clustering operations within the k-means algorithm.
4. features Class 
The `features` class provides an interface for applying the k-means algorithm to cluster data 
and visualizing the results. It prompts the user for input parameters, reads points from a data 
file, runs the k-means algorithm, and visualizes the outcomes.
 5. main Function 
The `main` function serves as the entry point for the program. It initiates k-means clustering 
and visualization using the `features` class. The function takes the name of the data file as 
input from the user, reads points from the file, executes the k-means algorithm, and visualizes 
the results. It controls the overall flow of the program.
These classes and functions collectively apply the k-means clustering algorithm to a dataset, 
providing results to the user. Each class takes on specific responsibilities, contributing to the 
modularity and readability of the program.
