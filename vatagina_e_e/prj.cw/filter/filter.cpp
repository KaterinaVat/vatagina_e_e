#include "filter/filter.hpp"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <ctikz/ctikz.hpp>
#include <opencv2/imgproc.hpp>

//! @brief Реализация Guided_filter 
void filter::visualization(cv::Mat& img, std::string name_add) {
	CTikz my_tex;
	int m = 20;
	std::vector<std::vector<double>> ar(m, std::vector<double>(m, 1));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			ar[i][j] = img.at<uchar>(i, j);

		}
	}
	std::vector<double> temp;
	int cnt = 0;
	for (int i = 0; i < 20; ++i) {
		temp.clear();
		for (int j = 0; j < 20; ++j) {
			temp.push_back(cnt);
			cnt += 1;
		}
		ar.push_back(temp);
	}
	my_tex.draw_table(ar);
	std::string name = "table_" + name_add;
	std::cout << "file " << name << " was build" << std::endl;
	my_tex.create_tikz_file(name);
}

cv::Mat filter::Guided_filter() {

	cv::Mat I = cv::imread(pass_, cv::IMREAD_GRAYSCALE);
	visualization(I, "I");
	cv::Mat p = cv::imread(pass_, cv::IMREAD_GRAYSCALE);
	int wsize = 2 * r_ + 1;
	cv::Mat mean_I;
	cv::boxFilter(I, mean_I, -1, cv::Size(wsize, wsize));
	visualization(mean_I, "mean_I");
	cv::Mat mean_p;
	cv::boxFilter(p, mean_p, -1, cv::Size(wsize, wsize));

	cv::Mat mean_II;
	mean_II = I.mul(I) / 255;
	cv::boxFilter(mean_II, mean_II, -1, cv::Size(wsize, wsize));
	visualization(mean_I, "mean_I");

	//corrIp=fmean(I.*p)
	cv::Mat mean_Ip;
	mean_Ip = I.mul(p) / 255;
	cv::boxFilter(mean_Ip, mean_Ip, -1, cv::Size(wsize, wsize));//Box filter


	//varI=corrI-meanI.*meanI
	cv::Mat var_I, mean_mul_I;
	mean_mul_I = mean_I.mul(mean_I) / 255;
	var_I = mean_II - mean_mul_I;
	//visualization(var_I, "var_I");

	//covIp=corrIp-meanI.*meanp
	cv::Mat cov_Ip;
	cov_Ip = mean_Ip - mean_I.mul(mean_p) / 255;


	//a=conIp./(varI+eps)
	//b=meanp-a.*meanI
	cv::Mat a, b;
	a = cov_Ip / (var_I + eps_);
	b = mean_p - a.mul(mean_I) / 255;
	visualization(a, "a");
	visualization(b, "b");


	//meana=fmean(a)
	//meanb=fmean(b)
	cv::Mat mean_a, mean_b;
	cv::boxFilter(a, mean_a, -1, cv::Size(wsize, wsize));//Box filter
	cv::boxFilter(b, mean_b, -1, cv::Size(wsize, wsize));//Box filter

	//q=meana.*I+meanb
	cv::Mat q;
	q = mean_a.mul(I) / 255 + mean_b;
	visualization(q, "q");

	return q;
}


filter::filter(const filter& other) {
	pass_ = other.pass_;
	r_ = other.r_;
	eps_ = other.eps_;
}

filter::filter(filter&& moved) noexcept :
	pass_(moved.pass_), r_(moved.r_), eps_(moved.eps_)
{
	moved.pass_ = "";
	moved.r_ = 0;
	moved.eps_ = 0.0;
}

filter& filter::operator=(const filter& other) {
	pass_ = other.pass_;
	r_ = other.r_;
	eps_ = other.eps_;
	return *this;
}
