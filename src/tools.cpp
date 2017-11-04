#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  // Take code from old exercise
  
  VectorXd rmse(4);
  rmse << 0,0,0,0;
  
  // Copy from the lecture exercise:
  if ((estimations.size() == 0) || (estimations.size() != ground_truth.size()))  {
    return rmse;
  }

  //accumulate squared residuals
  for(int i=0; i < estimations.size(); ++i) {
    VectorXd delta  =  estimations[i] - ground_truth[i];
    delta = delta.array() * delta.array();
    rmse += delta;
  }

  //calculate the mean
  rmse = rmse/estimations.size();

  //calculate the squared root
  rmse = rmse.array().sqrt();

  //return the result
  return rmse;
}

double Tools::NormalizeAngle(double angle) {
	while (angle> M_PI) angle-=2.*M_PI;
    while (angle<-M_PI) angle+=2.*M_PI;
	return angle;
}