#include <iostream>
#include <vector>
#include <cstdlib>
#include<conio.h>
#include <ctime>
#include "histogram.h"
#pragma hdrstop
#include "svg.h"
using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
int main()
{

    read_input(cin)
    const auto numbers = input_numbers(in,number_count);
    const auto bins = make_histogram(bin_size, bin_count);
    show_histogram_svg(bins);
    return 0;
}
