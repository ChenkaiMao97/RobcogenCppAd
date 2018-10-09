#include "acrobot_wrapper.h"
#include "forward_euler.h"
#include <chrono>
#include "eigen_util.h"
// #include <pybind11/pybind11.h>
// #include <pybind11/eigen.h>

// namespace py = pybind11;

using namespace robot_utils;

int main()
{


    //auto start = chrono::steady_clock::now();

    forward_euler fe;

    robot_wrapper robot(fe);
    robot.add_actuator(0);
    robot.add_actuator(1);
    std::vector<double> torque_limits;
    torque_limits.push_back(1.0);
    torque_limits.push_back(1.0);
    robot.set_torque_limits(torque_limits);


    Eigen::VectorXd q;
    Eigen::VectorXd qd;
    Eigen::VectorXd tau;


    Eigen::read_binary("q", q);
    Eigen::read_binary("qd", qd);
    Eigen::read_binary("tau", tau);

    Eigen::VectorXd qdd;


    //std::cout << qdd << std::endl;

    const double dt = 0.002;

    robot.simulate(q, qd, tau, dt);
    Eigen::write_binary("q", q);
    Eigen::write_binary("qd", qd);
     
/*
    Eigen::VectorXd q = Eigen::Vector2d::Random();
    Eigen::VectorXd qd = Eigen::Vector2d::Random();
    Eigen::VectorXd tau = Eigen::Vector2d::Random();
    test(q, qd, tau);
*/
    
    const int N = (int)(1.0 / dt);


    for (int i = 0; i < (int)(1.0 / dt); ++i){
        //robot.compute_fd(qdd, q, qd, tau);
        robot.simulate(q, qd, tau, dt);


    }

    auto end = chrono::steady_clock::now();

    std::cout << "elapsed time per iteration " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / N  << std::endl;
    std::cout << "Total elapsed time per second " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()  << std::endl;
    

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

    //auto end = chrono::steady_clock::now();


    //std::cout << "Total elapsed time is " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()  << std::endl;
}


// PYBIND11_MODULE(pybind_robots, m) {
//     m.doc() = "pybind11 example plugin"; // optional module docstring

//     m.def("acrobot_step", &acrobot_step, "Run simple test");
// }
