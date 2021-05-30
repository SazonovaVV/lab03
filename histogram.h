#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>

using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max);
vector<double> input_numbers(size_t count);
vector <size_t>make_histogram(vector<double> numbers, double bin_count,double number_count);
void show_histogram_text(vector <size_t>bins,double bin_count, double number_count);

#endif // HISTOGRAM_H_INCLUDED
