#include <filter/filter.hpp>
#include <ctikz/ctikz.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <exception>


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	try {
		if (argc < 4) {
			throw argc;
		}
		std::string file_pass = argv[1];
		int radius = atoi(argv[2]);
		double eps = atof(argv[3]);

		filter image(file_pass, radius, eps);
		cv::Mat I = cv::imread(file_pass, cv::IMREAD_GRAYSCALE);
		cv::Mat guided_image = image.Guided_filter();
		cv::imshow("first", I);
		cv::imshow("guided image", guided_image);
		cv::waitKey(0);

		if (argv[4]) {
			std::string pass_to_save = argv[4];
			if (pass_to_save[pass_to_save.length() - 1] != '/') {
				pass_to_save = pass_to_save + '/';
			}
			std::string img_name = pass_to_save + argv[5];
			cv::imwrite(img_name, guided_image);
		}
}
		catch (int argc) {
		std::cout << "Arguments are not enough: <pass to img> <r_> <eps>" << std::endl;
	}
}