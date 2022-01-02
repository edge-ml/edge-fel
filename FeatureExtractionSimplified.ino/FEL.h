#pragma once

#ifndef FEL_h
#define FEL_h

class FEL
{
private:
	double my_abs(double);
	double absolute_energy(double[], unsigned);
	double absolute_max(double[], unsigned);
	double absolute_sum_of_changes(double[], unsigned);
	double count_above_mean(double[], unsigned);
	double count_below_mean(double[], unsigned);
	double has_duplicate_values(double[], unsigned);
	double has_duplicate_maxima(double[], unsigned);
	double has_duplicate_minima(double[], unsigned);
	double mean(double[], unsigned);
	double maximum(double[], unsigned);
	double minimum(double[], unsigned);
	double first_location_of_maximum(double[], unsigned);
	double first_location_of_minimum(double[], unsigned);
	double last_location_of_maximum(double[], unsigned);
	double last_location_of_minimum(double[], unsigned);
	double sum_values(double[], unsigned);
	double variance(double[], unsigned);

public:
	double* extract(double[], unsigned, unsigned[], unsigned);
  double extract_one(double[], unsigned, int);
};

#endif
