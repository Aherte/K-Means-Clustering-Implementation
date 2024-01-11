#include "features.h"
features::features(const string& file, const string& output, int k, int Iters, int ID , const vector<Point>& points, const string& ln)
	: filename(file), output_dir(output), K(k), iters(Iters), pointId(ID),all_points(points), line(ln)
{

}

void features::runfeatures() {
	features_enter();
	readFromFile();
	features_visulize();
}

void features::features_enter() {
	cout << "enter k: ";
	cin >> K;
	cout << endl;

	cout << "enter iters: ";
	cin >> iters;
	cout << endl;
}

void features::readFromFile() {
	ifstream infile(filename.c_str());

	if (!infile.is_open())
	{
		cout << "Error: Failed to open file." << endl;
	}

	while (getline(infile, line))
	{
		Point point(pointId, line);
		all_points.push_back(point);
		pointId++;
	}

	infile.close();
	cout << "\nData fetched successfully!" << endl
		<< endl;

	if ((int)all_points.size() < K)
	{
		cout << "Error: Number of clusters greater than number of points." << endl;
	}

}

void features::features_visulize() {
	kmeans kmeans(K, iters, output_dir);
	cout << "Visulizing" << endl;
	kmeans.run(all_points); 

	plt::figure();

	vector<string> colors = { "bo", "go", "yo", "ko", "mo" };

	for (size_t i = 1; i <= K; i++)
	{
		for (size_t j = 0; j < all_points.size(); j++)
		{
			Point& point = all_points[j];
			if (point.getCluster() == i)
			{
				double x_value = all_points[j].getVal(0);
				double y_value = all_points[j].getVal(1);
				plt::plot({ x_value }, { y_value }, colors[i - 1]);
				plt::text(x_value + 5, y_value + 8, to_string(point.getID()));

			}
		}
		Cluster& cluster = kmeans.getCluster(i - 1);
		plt::plot({ cluster.getCentroidByPos(0) }, { cluster.getCentroidByPos(1) }, "rx");
	}

	plt::title("K=" + to_string(K));
	plt::legend();
	plt::show();
}