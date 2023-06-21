#include <opencv2/core.hpp>
#include <ctikz/ctikz.hpp>

/*!
	\file filter.hpp
	\brief ������������ ���� � ��������� ������

	����� �������� ���� ����� ��� ��������� �����������
	����������� ��������

*/
class filter {
private:
	std::string pass_ = ""; //!< ���� � ������������� �����������
	int r_ = 0; //!< ������ ���� ����-�������
	double eps_ = 0.0; //!< ��������
public:
	filter() = default;

	/*!
	  \brief ���������������� �����������
	  \param[in] pass ���� � ��������������� �����������
	  \param[in] r ������ ��������� ����-��������
	  \rapam[in] eps ��������
	*/
	filter(const std::string& pass, const int& r, const double& eps) :
		pass_(pass), r_(r), eps_(eps) {};

	filter(const filter& other);
	filter(filter&& moved) noexcept;

	filter& operator=(const filter& other);

	~filter() = default;

	/*!
	 \brief �������� ������������ �������
	 \param[out] q ������������ ����������� ����������� ��������

	 ������� ����� ��������� ��������� ����������� �����������
	 ��������, ������� �������� ����� ���������� ��������� ������� �
	 ���������� �������� � ����������� ����������� � ����� �������
	 ������������ ������������ ����������� � ������� �������

	 ��� ������� �������� ��������� �������:
	 \code
	cv::Mat filter::Guided_filter() {
	cv::Mat I = cv::imread(pass_);
	cv::Mat p = cv::imread(pass_);
	double eps = eps_;
	int wsize = 2 * r_ + 1;
	cv::Mat mean_I;
	cv::boxFilter(I, mean_I, -1, cv::Size(wsize, wsize));
	cv::Mat mean_p;
	cv::boxFilter(p, mean_p, -1, cv::Size(wsize, wsize));
	cv::Mat mean_II;
	mean_II = I.mul(I) / 255;
	cv::boxFilter(mean_II, mean_II, -1, cv::Size(wsize, wsize));
	cv::Mat mean_Ip;
	mean_Ip = I.mul(p) / 255;
	cv::boxFilter(mean_Ip, mean_Ip, -1, cv::Size(wsize, wsize));//Box filter
	cv::Mat var_I, mean_mul_I;
	mean_mul_I = mean_I.mul(mean_I) / 255;
	var_I = mean_II - mean_mul_I;
	cv::Mat cov_Ip;
	cov_Ip = mean_Ip - mean_I.mul(mean_p) / 255;
	cv::Mat a, b;
	a = cov_Ip / (var_I + eps);
	b = mean_p - a.mul(mean_I) / 255;
	cv::Mat mean_a, mean_b;
	cv::boxFilter(a, mean_a, -1, cv::Size(wsize, wsize));//Box filter
	cv::boxFilter(b, mean_b, -1, cv::Size(wsize, wsize));//Box filter
	cv::Mat q;
	q = mean_a.mul(I) / 255 + mean_b;
	return q;
	 \endcode
*/
	cv::Mat Guided_filter();
	void visualization(cv::Mat& img, std::string name_add);


	/*! \example example.cpp
	������ ����, ��� ������������ �����
	\code
	#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <filter/filter.hpp>

void main() {
	std::string file_pass = "C: / filter / IMAGE(3).png";
	int radius = 5;
	double eps = 0.1;

	filter image(file_pass, radius, eps);
	cv::Mat I = cv::imread(file_pass);
	cv::Mat guided_image = image.Guided_filter();
	cv::imshow("first", I);
	cv::imshow("guided image", guided_image);
	cv::waitKey(0);
}
\endcode
*/
};
