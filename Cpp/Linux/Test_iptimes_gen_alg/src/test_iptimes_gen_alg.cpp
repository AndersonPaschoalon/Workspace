//============================================================================
// Name        : test_iptimes_gen_alg.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "StochasticModelFit.h"
#include "RegressionTests.h"
using namespace std;

double summ_vector(vector<double>  &vec)
{
	//cout << "size = " << vec.size();
	uint size = vec.size();
	double summ = 0;

	for(uint i = 0; i < size; i++)
	{
		summ = summ +  vec[i];
	}
	return(summ);
}

bool regularize_iptimes(vector<double>& iptimes, double on_time, double reg_time){
	double time_i = 0;
	double ipt_summ = summ_vector(iptimes);

	if(ipt_summ < on_time){
		return(true);
	}
	else
	{
		for (uint i = 0; i < iptimes.size(); i++)
		{
			if(iptimes[i] > reg_time)
			{
				ipt_summ = ipt_summ - iptimes[i];
				iptimes[i] = 0;
				if(ipt_summ < on_time){
					return(true);
				}
			}
		}
	}
	return (false);
}
void print_vector(vector<double>& iptimes)
{
	for(uint i = 0; i < iptimes.size(); i++)
	{
		cout << iptimes[i] << ", ";
	}
	cout << endl;
}

/**
 * Esse algoritimo gera um vetor de tempos regularizados a partir de uma função estocastica.
 * Regularizados pois a soma dos valores nunca ultrapassa um limite
 * @return
 */

int main() {



	//StochasticModelFit model = StochasticModelFit();
	//model.unity_tests();
	double alpha = 1.2;
	double beta = 0.314;
	double aa = -15;
	double bb = -7;
	uint npackets = 20;
	vector<double> iptimes(npackets, 0);
	double ipt_summ = 0;
	double max_gen_time = 0;
	double sub_summ = 0;
	double on_time = 0.1;


	StochasticModelFit ipt = StochasticModelFit(WEIBULL, alpha, beta, aa, bb);

	for(uint i = 0; i < npackets; i++)
	{
		iptimes[i] = ipt.getRandom();
		ipt_summ += iptimes[i];
		max_gen_time = (iptimes[i] > max_gen_time)? iptimes[i] : max_gen_time;
	}
	sub_summ = ipt_summ;

	cout << "max_gen_time:" << max_gen_time << endl;
	cout << "summ before : " << summ_vector(iptimes) << endl;
	print_vector(iptimes);

	uint cc = 0;
	while(regularize_iptimes(iptimes, on_time, max_gen_time/2) == false)
	{
		cout << cc << endl;
		cc++;
		max_gen_time = max_gen_time/2;
	}
	print_vector(iptimes);
	cout << "summ after : " << summ_vector(iptimes) << endl;

	return 0;
}
