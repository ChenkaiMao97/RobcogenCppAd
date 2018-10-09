//
// Created by csg on 6/10/18.
//

#pragma once

//TODO: Parent class this and alloiw for lots of different types of arbitrary "simulators"...lazy for now

#include <Eigen/Dense>

namespace robot_utils {

    //TODO: Do we want to template this on scalars?
    class forward_euler {

    public:
        void simulate(Eigen::VectorXd& q, Eigen::VectorXd& qd, const Eigen::VectorXd& qdd, const double dt){
            //q_out = q + dt * qd;
            //qd_out = qd + dt * qdd;
            q += dt * qd;
            qd += dt * qdd;

        }



    };



}