//
// Created by csg on 6/10/18.
//

#pragma once

#include <iit/rbd/rbd.h>
#include <cppad/cppad.hpp>
#include <cppad/core/value.hpp>
#include <cppad/example/cppad_eigen.hpp>

#include <algorithm>


//TODO: replace these via a script
#include "../gen_code/cpp/acrobot/declarations.h"
#include "../gen_code/cpp/acrobot/inertia_properties.h"
#include "../gen_code/cpp/acrobot/transforms.h"
#include "../gen_code/cpp/acrobot/inverse_dynamics.h"
#include "../gen_code/cpp/acrobot/forward_dynamics.h"

#include <iostream>
#include "forward_euler.h"



namespace robot_utils {

    using namespace iit;
    using namespace std;

    struct CppADDoubleTrait {

        typedef double   PrimitiveScalar;
        typedef CppAD::AD<double> Scalar;

        inline static Scalar sin(const Scalar& x) { return CppAD::sin(x); }
        inline static Scalar cos(const Scalar& x) { return CppAD::cos(x); }

        template <int Dims>
        inline static Eigen::Matrix<Scalar, Dims, 1> solve(const Eigen::Matrix<Scalar, Dims, Dims>& A, const Eigen::Matrix<Scalar, Dims, 1>& b)
        {
            return A.inverse()*b;
        }
    };


    typedef CppAD::AD<double>    AD_double;
    typedef rbd::Core<AD_double> AD_Types;

    typedef CppADDoubleTrait       Trait;
    typedef typename Trait::Scalar Scalar;
    typedef typename Trait::PrimitiveScalar PrimitiveScalar;

    typedef Acrobot::tpl::JointState<Scalar> AD_JointState;

    static constexpr int q_dim = Acrobot::jointsCount;

    class robot_wrapper {

    protected:
        std::vector<int> actuators_to_index;
        std::vector<double> torque_limits;
        forward_euler fe;

    public:

        robot_wrapper(const forward_euler& fe){
            this->fe = fe;
        }

        void simulate(Eigen::VectorXd& q, Eigen::VectorXd& qd, Eigen::VectorXd& tau, const double dt){

            Eigen::VectorXd qdd;

            compute_fd(qdd, q, qd, tau);
            this->fe.simulate(q, qd, qdd, dt);

        }

        void add_actuator(int idx){
            //first, check if idx is already in the map:

            if (std::find(actuators_to_index.begin(), actuators_to_index.end(), idx) == actuators_to_index.end()){
                //if it's not in the map, let's add it.
                actuators_to_index.push_back(idx);
            }

        } //add an actuator at index idx;

        void set_torque_limits(const std::vector<double>& torque_limits){

            if (torque_limits.size() > actuators_to_index.size()){
                throw std::runtime_error("Torque limits cannot be larger than the number of actuators");
            }

            this->torque_limits = torque_limits;
        }

        void set_tau(Eigen::VectorXd& tau) const {

            Eigen::VectorXd tau_out = Eigen::VectorXd::Zero(q_dim);

            for (int i = 0; i < actuators_to_index.size(); ++i){
                tau_out(actuators_to_index.at(i)) = max(min(tau(i), torque_limits.at(i)), -torque_limits.at(i));
            }

            tau = tau_out;
        }

        void compute_fd(Eigen::VectorXd& qdd_return, const Eigen::VectorXd& q, const Eigen::VectorXd& qd, Eigen::VectorXd& tau) const {


            set_tau(tau);


            const int u_dim = actuators_to_index.size();

            const int dep_vars = u_dim + 2 * q_dim;

            Acrobot::     tpl::MotionTransforms <Trait> xm;
            Acrobot::dyn::tpl::InertiaProperties<Trait> ip;
            Acrobot::dyn::tpl::ForwardDynamics  <Trait> fd(ip, xm);

            // joint status init
            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> state_and_torque( dep_vars );
            AD_JointState qdd;



            state_and_torque.segment<q_dim>(0) = q.cast<CppAD::AD<double> >();
            state_and_torque.segment<q_dim>(q_dim) = qd.cast<CppAD::AD<double> >();
            state_and_torque.segment(2 * q_dim, u_dim) = tau.cast<CppAD::AD<double> >();



            qdd.setZero();

            // Run the algorithm and "record" it
            // CppAD requires dynamic vectors ... so a few conversions are necessary

            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_state_and_torque( dep_vars );
            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_qdd( q_dim );



            AD_state_and_torque = state_and_torque;
            CppAD::Independent( AD_state_and_torque );
            state_and_torque = AD_state_and_torque;  // do not remove! It is NOT redundant!

            fd.fd(qdd, state_and_torque.segment<q_dim>(0), state_and_torque.segment<q_dim>(q_dim), state_and_torque.segment(2 * q_dim, u_dim));
            AD_qdd = qdd;

            CppAD::ADFun<double> f( AD_state_and_torque, AD_qdd );
            //f.optimize();


            std::vector<PrimitiveScalar> x( dep_vars );
            for(int i=0; i< x.size(); i++) {
                x[i] = CppAD::Value(state_and_torque(i));
            }

            std::vector<double> forward = f.Forward(0, x);

            qdd_return = Eigen::Matrix<double, q_dim, 1>();

            if (qdd_return.size() != forward.size()){
                throw std::runtime_error("The dimension of qdd did not match q_dim");
            }

            for (int i = 0; i < forward.size(); ++i){
                qdd_return(i) = forward[i];
            }





        }

        //TODO: force field?






    };









}


Eigen::VectorXd acrobot_step(Eigen::VectorXd& q, Eigen::VectorXd& qd, Eigen::VectorXd& tau){



    robot_utils::forward_euler fe;

    robot_utils::robot_wrapper robot(fe);
    robot.add_actuator(0);
    robot.add_actuator(1);
    std::vector<double> torque_limits;
    torque_limits.push_back(1.0);
    torque_limits.push_back(1.0);
    robot.set_torque_limits(torque_limits);





    const double dt = 0.002;



    robot.simulate(q, qd, tau, dt);


    Eigen::VectorXd ret_vec(q.size() + qd.size() + tau.size());

    ret_vec << q, qd, tau;

    return ret_vec;
/*
    std::cout << q << std::endl;
    std::cout << qd << std::endl;
    std::cout << tau << std::endl;
*/
    //std::cout << "DONE" << std::endl;



}