#include "histogram.h"
#include <vector>
#include <iostream>
#include<conio.h>

using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max)
{
    if(numbers.size()==0){
        return;
    }
  min = numbers[0];
  max = numbers[0];
    for (double number : numbers)
 {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
 }
 return;
}
vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}
vector <size_t>
make_histogram(vector<double> numbers, double bin_count,double number_count)
{

    double max, min;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    vector<size_t> bins(bin_count);
    for(int i = 0; i < number_count; i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}
