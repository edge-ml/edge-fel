#include <vector>
#include <iostream>

using namespace std;

double absolute_energy(vector<double> x) // Returns the absolute energy of the time series which is the sum over the squared values.
{
    try
    {
        double result = 0;
        for (int i = 0; i < x.size(); i++)
            {
                result += x[i]*x[i];
            }
        
        return result;
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

double absolute_max(vector<double> x) // Calculates the highest absolute value of the time series x.
{
    try
    {
        double result = abs(x[0]);
        for (int i = 1; i < x.size(); i++)
        {
            if (abs(x[i]) > result)
                {
                    result = abs(x[i]);
                }
        }

        return result;
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

double absolute_sum_of_changes(vector<double> x) // Returns the sum over the absolute value of consecutive changes in the series x.
{
    try
    {
        double result = 0;
        for (int i = 0; i < x.size() - 1; i++)
        {
            result += abs(x[i+1] - x[i]);
        }

        return result;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

unsigned count_above_mean(vector<double> x) // Returns the number of values in x that are higher than the mean of x.
{
    try
    {
        unsigned result = 0;
        double mean;
        double sum = 0;
        for (int i = 0; i < x.size(); i++)
        {
            sum += x[i];
        }
        mean = sum/x.size();

        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] > mean)
            {
                result++;
            }
        }

        return result;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

unsigned count_below_mean(vector<double> x) // Returns the number of values in x that are lower than the mean of x.
{
    try
    {
        unsigned result = 0;
        double mean;
        double sum = 0;
        for (int i = 0; i < x.size(); i++)
        {
            sum += x[i];
        }
        mean = sum/x.size();

        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] < mean)
            {
                result++;
            }
        }

        return result;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

bool has_duplicate_values(vector<double> x) // Checks if any value in x occurs more than once.
{
    try
    {
        for (int i = 0; i < x.size() - 1; i++)
        {
            for (int j = i + 1; j < x.size(); j++)
            {
                if (x[i] == x[j])
                {
                    return true;
                }
            }
        }

        return false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

bool has_duplicate_maxima(vector<double> x) // Checks if the maximum value of x is observed more than once.
{
    try
    {
        double max = x[0];
        unsigned counter_of_maxima = 0;
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] > max)
            {
                max = x[i];
            }
        }

        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] == max)
            {
                counter_of_maxima++;
                if (counter_of_maxima == 2)
                {
                    return true;
                }
            }
        }

        return false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

bool has_duplicate_minima(vector<double> x) // Checks if the minimum value of x is observed more than once.
{
    try
    {
        double min = x[0];
        unsigned counter_of_minima = 0;
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] < min)
            {
                min = x[i];
            }
        }

        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] == min)
            {
                counter_of_minima++;
                if (counter_of_minima == 2)
                {
                    return true;
                }
            }
        }

        return false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

double mean(vector<double> x) // Returns the mean of x.
{
    try
    {
        double sum = 0;
        for (int i = 0; i < x.size(); i++)
        {
            sum += x[i];
        }

        return sum/x.size();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

double maximum(vector<double> x) // Calculates the highest value of the time series x.
{
    try
    {
        double max = x[0];
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] > max)
            {
                max = x[i];
            }

        }

        return max;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

double minimum(vector<double> x) // Calculates the lowest value of the time series x.
{
     try
    {
        double min = x[0];
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] < min)
            {
                min = x[i];
            }
        }

        return min;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

unsigned first_location_of_maximum(vector<double> x) // Returns the first location of the maximum value of x.
{
    try
    {
        double max = x[0];
        unsigned location = 0;
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] > max)
            {
                max = x[i];
                location = i;
            }

        }

        return location;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

double first_location_of_minimum(vector<double> x) // Returns the first location of the minimum value of x.
{
     try
    {
        double min = x[0];
        unsigned location = 0;
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] < min)
            {
                min = x[i];
                location = i;
            }
        }

        return location;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

unsigned last_location_of_maximum(vector<double> x) // Returns the last location of the maximum value of x.
{
    try
    {
        double max = x[x.size() - 1];
        unsigned location = x.size() - 1;
        for (int i = x.size() - 2; i > 0; i--)
        {
            if (x[i] > max)
            {
                max = x[i];
                location = i;
            }

        }

        return location;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

unsigned last_location_of_minimum(vector<double> x) // Returns the last location of the minimum value of x.
{
    try
    {
        double min = x[x.size() - 1];
        unsigned location = x.size() - 1;
        for (int i = x.size() - 2; i > 0; i--)
        {
            if (x[i] < min)
            {
                min = x[i];
                location = i;
            }

        }

        return location;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

double sum_values(vector<double> x) // Calculates the sum over the time series x values.
{
    try
    {
        double sum = 0;
        for (int i = 0; i < x.size(); i++)
        {
            sum += x[i];
        }

        return sum;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

double variance(vector<double> x) // Returns the variance of x.
{
    try
    {
        double sum = 0;
        double mean;
        double tmp = 0;
        for (int i = 0; i < x.size(); i++)
        {
            sum += x[i];
        }
        mean = sum/x.size();

        for (int i = 0; i < x.size(); i++)
        {
            tmp += (x[i]-mean)*(x[i]-mean);
        }

        return tmp/x.size();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

auto extract(vector<double> x, unsigned id)
{
    switch (id)
    {
        case 0: return absolute_energy(x); break;
        case 1: return absolute_max(x); break;
        case 2: return absolute_sum_of_changes(x); break;
        case 3: return count_above_mean(x); break;
        default: return 0;
    }
}