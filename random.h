#ifndef _RANDOM_
#define _RANDOM_

inline
double random_double(const double min, const double max)
{
	double range = max - min;
	return min + (double(rand()) / double(RAND_MAX)) * range;
}

inline
int random_int(const int min, const int max)
{
    int range = max - min;
    return min + int((double(rand())/double(RAND_MAX)) * range);
}

#endif
