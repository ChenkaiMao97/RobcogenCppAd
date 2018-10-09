
/*
#include <iit/rbd/rbd.h>


#include "../gen_code/cpp/acrobot/declarations.h"
#include "../gen_code/cpp/acrobot/inertia_properties.h"
#include "../gen_code/cpp/acrobot/transforms.h"
#include "../gen_code/cpp/acrobot/inverse_dynamics.h"
#include "../gen_code/cpp/acrobot/forward_dynamics.h"

#include <cppad/cppad.hpp>
#include <cppad/core/value.hpp>
#include <cppad/example/cppad_eigen.hpp>

#include <iostream>

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

static constexpr int size = Acrobot::jointsCount;
*/

#include "robot_wrapper.h"
#include "forward_euler.h"

using namespace robot_utils;

int main()
{

    forward_euler fe;

    robot_wrapper robot(fe);
    robot.add_actuator(0);
    robot.add_actuator(1);
    std::vector<double> torque_limits;
    torque_limits.push_back(1.0);
    torque_limits.push_back(1.0);
    robot.set_torque_limits(torque_limits);


    Eigen::VectorXd q = Eigen::Vector2d::Random();
    Eigen::VectorXd qd = Eigen::Vector2d::Random();
    Eigen::VectorXd tau = Eigen::Vector2d::Random();


    Eigen::VectorXd qdd;
    robot.compute_fd(qdd, q, qd, tau);

    std::cout << qdd << std::endl;

    const double dt = 0.05;

    for (int i = 0; i < (int)(1.0 / dt); ++i){
        robot.simulate(q, qd, tau, dt);
        std::cout << q << std::endl;
        std::cout << qd << std::endl;
    }
    /*
    // instantiate inverse dynamics
    Acrobot::     tpl::MotionTransforms <Trait> xm;
    Acrobot::dyn::tpl::InertiaProperties<Trait> ip;
    Acrobot::dyn::tpl::InverseDynamics  <Trait> id(ip, xm);
    Acrobot::dyn::tpl::ForwardDynamics  <Trait> fd(ip, xm);

    // joint status init
    Eigen::Matrix<Scalar, Eigen::Dynamic, 1> state_and_torque( 3 * size );
    AD_JointState qdd;

    state_and_torque.setRandom();


    qdd.setZero();

    // Run the algorithm and "record" it    
    // CppAD requires dynamic vectors ... so a few conversions are necessary

    Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_state_and_torque( 3 * size );
    Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_qdd( size );



    AD_state_and_torque = state_and_torque;
    CppAD::Independent( AD_state_and_torque );
    state_and_torque = AD_state_and_torque;  // do not remove! It is NOT redundant!

    fd.fd(qdd, state_and_torque.segment<size>(0), state_and_torque.segment<size>(size), state_and_torque.segment<size>(2 * size));
    AD_qdd = qdd;

    CppAD::ADFun<double> f( AD_state_and_torque, AD_qdd );





    // Get the Jacobian and evaluate it in some point
    std::vector<PrimitiveScalar> jac( 3 * size*size ); 	// Jacobian of f (m by n matrix)
    std::vector<PrimitiveScalar> x( 3 * size );
    for(int i=0; i<3 * size; i++) {
        x[i] = CppAD::Value( state_and_torque(i) ); // or something else
    }

    jac = f.Jacobian( x );

    for(int r=0; r<size; r++) {
        for(int c=0; c<3 * size; c++) {
            cout << " " << jac[r*size + c];
        }
        cout << endl;
    }
    cout << endl << endl;
    //cout << tau << endl;
     */
}