#if 0

#include "declarations.h"
#include "transforms.h"







int main(int argc, char *argv[])
{

iit::Fancy::MotionTransforms xm;
iit::Fancy::JointState q;
for (int i = 0; i < q.size(); ++i){
std::cout << i << std::endl;
q(i) = (double)i;
}
//q = ... // set the joint status
std::cout << xm.fr_link2_X_fr_link3(q) << std::endl;



/*
// [...]
    iit::Fancy::JointState q, qd, qdd, tau;
// [...]


    MotionTransforms transforms;
    dyn::InertiaProperties inertias;
    dyn::InverseDynamics invdyn(inertias, transforms);

    invdyn.id(tau, q, qd, qdd);
    */

return 1;
}

#endif
#if 0
#include "declarations.h"
#include "inertia_properties.h"
#include "transforms.h"
#include "inverse_dynamics.h"
#include <iit/rbd/traits/DoubleTrait.h>

#include <iostream>

using namespace iit;
using namespace std;

int main()
{
    typedef rbd::DoubleTrait       Trait;
    typedef typename Trait::Scalar Scalar;


    Fancy::dyn::tpl::InertiaProperties<Trait> ip;
    Fancy::tpl::MotionTransforms<Trait> xm;
    Fancy::dyn::tpl::InverseDynamics<Trait> id(ip, xm);

    Fancy::tpl::JointState<Scalar> q, qd, qdd, tau;
    q.setZero();
    qd.setZero();
    qdd.setZero();
    tau.setZero();

    id.id(tau, q, qd, qdd);

    cout << tau << endl;
}

#endif

#include <iit/rbd/rbd.h>

#include "declarations.h"
#include "inertia_properties.h"
#include "transforms.h"
#include "inverse_dynamics.h"

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

typedef Fancy::tpl::JointState<Scalar> AD_JointState;

static constexpr int size = Fancy::jointsCount;

int main() {
    AD_double offset;
    // instantiate inverse dynamics


    iit::Fancy::Params_lengths pl;
    pl.ee_x = 2.0;

    iit::Fancy::ParamsGetter_lengths pgl;
    pgl.pl = pl;


    Fancy::tpl::MotionTransforms<Trait> xm(pgl);
    pl.ee_x = 7.0;
    xm.updateParameters();


    Fancy::dyn::tpl::InertiaProperties<Trait> ip;
    Fancy::dyn::tpl::InverseDynamics<Trait> id(ip, xm);

    // joint status init
    AD_JointState q, qd, qdd, tau;
    q.setRandom();
    qd.setRandom();
    qdd.setRandom();




    const double eps = 1e-6;


    const int design_vars = 1;



    auto start = chrono::steady_clock::now();

    for (int i = 0; i < design_vars; ++i) {



        std::vector<PrimitiveScalar> jac_high(size * size);    // Jacobian of f (m by n matrix)
        std::vector<PrimitiveScalar> jac_low(size * size);    // Jacobian of f (m by n matrix)


        {

            pl.ee_x = 7.0 + eps;
            xm.updateParameters();

            tau.setZero();

            // Run the algorithm and "record" it
            // CppAD requires dynamic vectors ... so a few conversions are necessary
            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_qdd(size);
            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_tau(size);

            AD_qdd = qdd;
            CppAD::Independent(AD_qdd);
            qdd = AD_qdd;  // do not remove! It is NOT redundant!

            id.id(tau, q, qd, qdd);
            AD_tau = tau;

            CppAD::ADFun<double> f(AD_qdd, AD_tau);

            f.optimize();

            // Get the Jacobian and evaluate it in some point

            std::vector<PrimitiveScalar> x(size);
            for (int i = 0; i < size; i++) {
                x[i] = 0.0; // or CppAD::Value( qdd(i) ); // or something else
            }


            jac_high = f.Jacobian(x);
        }


        {

            pl.ee_x = 7.0 - eps;
            xm.updateParameters();

            tau.setZero();

            // Run the algorithm and "record" it
            // CppAD requires dynamic vectors ... so a few conversions are necessary
            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_qdd(size);
            Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_tau(size);

            AD_qdd = qdd;
            CppAD::Independent(AD_qdd);
            qdd = AD_qdd;  // do not remove! It is NOT redundant!

            id.id(tau, q, qd, qdd);
            AD_tau = tau;

            CppAD::ADFun<double> f(AD_qdd, AD_tau);

            f.optimize();

            // Get the Jacobian and evaluate it in some point
            std::vector<PrimitiveScalar> jac(size * size);    // Jacobian of f (m by n matrix)
            std::vector<PrimitiveScalar> x(size);
            for (int i = 0; i < size; i++) {
                x[i] = 0.0; // or CppAD::Value( qdd(i) ); // or something else
            }


            jac_low = f.Jacobian(x);
        }

        auto end= chrono::steady_clock::now();

        std::cout << "Elapsed time is " << chrono::duration_cast<chrono::nanoseconds>(start - end).count() << std::endl;

        for(int r=0; r<size; r++) {
            for(int c=0; c<size; c++) {
                cout << " " << (jac_high[r*size + c] - jac_high[r*size + c]) / 2.0;
            }
            cout << endl;
        }


    }



/*
    tau.setZero();

    // Run the algorithm and "record" it
    // CppAD requires dynamic vectors ... so a few conversions are necessary
    Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_qdd( size );
    Eigen::Matrix<Scalar, Eigen::Dynamic, 1> AD_tau( size );

    AD_qdd = qdd;
    CppAD::Independent( AD_qdd );
    qdd = AD_qdd;  // do not remove! It is NOT redundant!

    id.id(tau, q, qd, qdd);
    AD_tau = tau;

    CppAD::ADFun<double> f( AD_qdd, AD_tau );

    // Get the Jacobian and evaluate it in some point
    std::vector<PrimitiveScalar> jac( size*size ); 	// Jacobian of f (m by n matrix)
    std::vector<PrimitiveScalar> x( size );
    for(int i=0; i<size; i++) {
        x[i] = 0.0; // or CppAD::Value( qdd(i) ); // or something else
    }

    auto start = chrono::steady_clock::now();

    jac = f.Jacobian( x );

    auto end = chrono::steady_clock::now();

    std::cout << "Elapsed time is " << chrono::duration_cast<chrono::nanoseconds>(start - end).count() << std::endl;

    for(int r=0; r<size; r++) {
        for(int c=0; c<size; c++) {
            cout << " " << jac[r*size + c];
        }
        cout << endl;
    }
    cout << endl << endl;
    //cout << tau << endl;
    */
}
