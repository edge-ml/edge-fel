#include "FEL.h"

double FEL::my_abs(double value)
{
    return (value >= 0) ? value : -1;
}

double FEL::absolute_energy(double values[], unsigned size) // Returns the absolute energy of the time series which is the sum over the squared values.
{
    try
    {

        double result = 0;
        for (int i = 0; i < size; i++)
        {
            result += values[i] * values[i];
        }

        return result;
    }

    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::absolute_max(double values[], unsigned size) // Calculates the highest absolute value of the time series values.
{
    try
    {

        double result = my_abs(values[0]);
        for (int i = 1; i < size; i++)
        {
            if (my_abs(values[i]) > result)
            {
                result = my_abs(values[i]);
            }
        }

        return result;
    }

    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::absolute_sum_of_changes(double values[], unsigned size) // Returns the sum over the absolute value of consecutive changes in the series values.
{
    try
    {

        double result = 0;
        for (int i = 0; i < size - 1; i++)
        {
            result += my_abs(values[i + 1] - values[i]);
        }

        return result;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::count_above_mean(double values[], unsigned size) // Returns the number of values in values that are higher than the mean of values.
{
    try
    {

        double result = 0;
        double mean;
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += values[i];
        }
        mean = sum / size;

        for (int i = 0; i < size; i++)
        {
            if (values[i] > mean)
            {
                result++;
            }
        }

        return result;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::count_below_mean(double values[], unsigned size) // Returns the number of values in values that are lower than the mean of values.
{
    try
    {

        double result = 0;
        double mean;
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += values[i];
        }
        mean = sum / size;

        for (int i = 0; i < size; i++)
        {
            if (values[i] < mean)
            {
                result++;
            }
        }

        return result;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::has_duplicate_values(double values[], unsigned size) // Checks if any value in values occurs more than once.
{
    try
    {

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (values[i] == values[j])
                {
                    return 1;
                }
            }
        }

        return 0;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::has_duplicate_maxima(double values[], unsigned size) // Checks if the maximum value of values is observed more than once.
{
    try
    {

        double max = values[0];
        int counter_of_maxima = 0;
        for (int i = 1; i < size; i++)
        {
            if (values[i] > max)
            {
                max = values[i];
            }
        }

        for (int i = 1; i < size; i++)
        {
            if (values[i] == max)
            {
                counter_of_maxima++;
                if (counter_of_maxima == 2)
                {
                    return 1;
                }
            }
        }

        return 0;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::has_duplicate_minima(double values[], unsigned size) // Checks if the minimum value of values is observed more than once.
{
    try
    {

        double min = values[0];
        int counter_of_minima = 0;
        for (int i = 1; i < size; i++)
        {
            if (values[i] < min)
            {
                min = values[i];
            }
        }

        for (int i = 1; i < size; i++)
        {
            if (values[i] == min)
            {
                counter_of_minima++;
                if (counter_of_minima == 2)
                {
                    return 1;
                }
            }
        }

        return 0;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::mean(double values[], unsigned size) // Returns the mean of values.
{
    try
    {

        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += values[i];
        }

        return sum / size;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::maximum(double values[], unsigned size) // Calculates the highest value of the time series values.
{
    try
    {

        double max = values[0];
        for (int i = 1; i < size; i++)
        {
            if (values[i] > max)
            {
                max = values[i];
            }

        }

        return max;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::minimum(double values[], unsigned size) // Calculates the lowest value of the time series values.
{
    try
    {

        double min = values[0];
        for (int i = 1; i < size; i++)
        {
            if (values[i] < min)
            {
                min = values[i];
            }
        }

        return min;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::first_location_of_maximum(double values[], unsigned size) // Returns the first location of the maximum value of values.
{
    try
    {

        double max = values[0];
        double location = 0;
        for (int i = 1; i < size; i++)
        {
            if (values[i] > max)
            {
                max = values[i];
                location = i;
            }

        }

        return location;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::first_location_of_minimum(double values[], unsigned size) // Returns the first location of the minimum value of values.
{
    try
    {

        double min = values[0];
        int location = 0;
        for (int i = 1; i < size; i++)
        {
            if (values[i] < min)
            {
                min = values[i];
                location = i;
            }
        }

        return location;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::last_location_of_maximum(double values[], unsigned size) // Returns the last location of the maximum value of values.
{
    try
    {

        double max = values[size - 1];
        double location = size - 1;
        for (int i = size - 2; i >= 0; i--)
        {
            if (values[i] > max)
            {
                max = values[i];
                location = i;
            }

        }

        return location;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::last_location_of_minimum(double values[], unsigned size) // Returns the last location of the minimum value of values.
{
    try
    {

        double min = values[size - 1];
        double location = size - 1;
        for (int i = size - 2; i >= 0; i--)
        {
            if (values[i] < min)
            {
                min = values[i];
                location = i;
            }

        }

        return location;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::sum_values(double values[], unsigned size) // Calculates the sum over the time series values values.
{
    try
    {

        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += values[i];
        }

        return sum;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double FEL::variance(double values[], unsigned size) // Returns the variance of values.
{
    try
    {

        double sum = 0;
        double mean;
        double tmp = 0;
        for (int i = 0; i < size; i++)
        {
            sum += values[i];
        }
        mean = sum / size;

        for (int i = 0; i < size; i++)
        {
            tmp += (values[i] - mean) * (values[i] - mean);
        }

        return tmp / size;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double FEL::extract_one(double values[], unsigned size, int id)
{
    switch (id)
    {
    case 0: return absolute_energy(values, size); break;
    case 1: return absolute_max(values, size); break;
    case 2: return absolute_sum_of_changes(values, size); break;
    case 3: return count_above_mean(values, size); break;
    case 4: return count_below_mean(values, size); break;
    case 5: return has_duplicate_values(values, size); break;
    case 6: return has_duplicate_maxima(values, size); break;
    case 7: return has_duplicate_minima(values, size); break;
    case 8: return mean(values, size); break;
    case 9: return maximum(values, size); break;
    case 10: return minimum(values, size); break;
    case 11: return first_location_of_maximum(values, size); break;
    case 12: return first_location_of_minimum(values, size); break;
    case 13: return last_location_of_maximum(values, size); break;
    case 14: return last_location_of_minimum(values, size); break;
    case 15: return sum_values(values, size); break;
    case 16: return variance(values, size); break;
    default: return 0; break;
    }
}

double* FEL::extract(double values[], unsigned size_values, unsigned id[], unsigned size_id)
{
    double* result = new double[size_id];

    for (int i = 0; i < size_id; i++)
    {
        result[i] = extract_one(values, size_values, id[i]);
    }

    return result;
}