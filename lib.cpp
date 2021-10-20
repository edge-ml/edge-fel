double my_abs(double x)
{
    return (x >= 0) ? x : -1;
}

double absolute_energy(double x[]) // Returns the absolute energy of the time series which is the sum over the squared values.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double result = 0;
        for (int i = 0; i < size; i++)
        {
            result += x[i] * x[i];
        }

        return result;
    }

    catch (...)
    {
        throw "Error occured";
    }
}

double absolute_max(double x[]) // Calculates the highest absolute value of the time series x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double result = my_abs(x[0]);
        for (int i = 1; i < size; i++)
        {
            if (my_abs(x[i]) > result)
            {
                result = my_abs(x[i]);
            }
        }

        return result;
    }

    catch (...)
    {
        throw "Error occured";
    }

}

double absolute_sum_of_changes(double x[]) // Returns the sum over the absolute value of consecutive changes in the series x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double result = 0;
        for (int i = 0; i < size - 1; i++)
        {
            result += my_abs(x[i + 1] - x[i]);
        }

        return result;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double count_above_mean(double x[]) // Returns the number of values in x that are higher than the mean of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double result = 0;
        double mean;
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += x[i];
        }
        mean = sum / size;

        for (int i = 0; i < size; i++)
        {
            if (x[i] > mean)
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

double count_below_mean(double x[]) // Returns the number of values in x that are lower than the mean of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double result = 0;
        double mean;
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += x[i];
        }
        mean = sum / size;

        for (int i = 0; i < size; i++)
        {
            if (x[i] < mean)
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

double has_duplicate_values(double x[]) // Checks if any value in x occurs more than once.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (x[i] == x[j])
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

double has_duplicate_maxima(double x[]) // Checks if the maximum value of x is observed more than once.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double max = x[0];
        int counter_of_maxima = 0;
        for (int i = 1; i < size; i++)
        {
            if (x[i] > max)
            {
                max = x[i];
            }
        }

        for (int i = 1; i < size; i++)
        {
            if (x[i] == max)
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

double has_duplicate_minima(double x[]) // Checks if the minimum value of x is observed more than once.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double min = x[0];
        int counter_of_minima = 0;
        for (int i = 1; i < size; i++)
        {
            if (x[i] < min)
            {
                min = x[i];
            }
        }

        for (int i = 1; i < size; i++)
        {
            if (x[i] == min)
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

double mean(double x[]) // Returns the mean of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += x[i];
        }

        return sum / size;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double maximum(double x[]) // Calculates the highest value of the time series x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double max = x[0];
        for (int i = 1; i < size; i++)
        {
            if (x[i] > max)
            {
                max = x[i];
            }

        }

        return max;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double minimum(double x[]) // Calculates the lowest value of the time series x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double min = x[0];
        for (int i = 1; i < size; i++)
        {
            if (x[i] < min)
            {
                min = x[i];
            }
        }

        return min;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double first_location_of_maximum(double x[]) // Returns the first location of the maximum value of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double max = x[0];
        double location = 0;
        for (int i = 1; i < size; i++)
        {
            if (x[i] > max)
            {
                max = x[i];
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

double first_location_of_minimum(double x[]) // Returns the first location of the minimum value of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double min = x[0];
        int location = 0;
        for (int i = 1; i < size; i++)
        {
            if (x[i] < min)
            {
                min = x[i];
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

double last_location_of_maximum(double x[]) // Returns the last location of the maximum value of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double max = x[size - 1];
        double location = size - 1;
        for (int i = size - 2; i > 0; i--)
        {
            if (x[i] > max)
            {
                max = x[i];
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

double last_location_of_minimum(double x[]) // Returns the last location of the minimum value of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double min = x[size - 1];
        double location = size - 1;
        for (int i = size - 2; i > 0; i--)
        {
            if (x[i] < min)
            {
                min = x[i];
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

double sum_values(double x[]) // Calculates the sum over the time series x values.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += x[i];
        }

        return sum;
    }
    catch (...)
    {
        throw "Error occured";
    }

}

double variance(double x[]) // Returns the variance of x.
{
    try
    {
        int size = sizeof(x) / sizeof(double);
        double sum = 0;
        double mean;
        double tmp = 0;
        for (int i = 0; i < size; i++)
        {
            sum += x[i];
        }
        mean = sum / size;

        for (int i = 0; i < size; i++)
        {
            tmp += (x[i] - mean) * (x[i] - mean);
        }

        return tmp / size;
    }
    catch (...)
    {
        throw "Error occured";
    }
}

double extract_one(double x[], int id)
{
    switch (id)
    {
    case 0: return absolute_energy(x); break;
    case 1: return absolute_max(x); break;
    case 2: return absolute_sum_of_changes(x); break;
    case 3: return count_above_mean(x); break;
    case 4: return count_below_mean(x); break;
    case 5: return has_duplicate_values(x); break;
    case 6: return has_duplicate_maxima(x); break;
    case 7: return has_duplicate_minima(x); break;
    case 8: return mean(x); break;
    case 9: return maximum(x); break;
    case 10: return minimum(x); break;
    case 11: return first_location_of_maximum(x); break;
    case 12: return first_location_of_minimum(x); break;
    case 13: return last_location_of_maximum(x); break;
    case 14: return last_location_of_minimum(x); break;
    case 15: return sum_values(x); break;
    case 16: return variance(x); break;
    default: return 0; break;
    }
}

double *extract(double x[], int id[])
{
    int size_of_id = sizeof(id) / sizeof(int);
    double *result = new double[size_of_id];

    for (int i = 0; i < size_of_id; i++)
    {
        result[i] = extract_one(x, id[i]);
    }

    return result;
}