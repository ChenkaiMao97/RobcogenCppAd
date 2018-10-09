#ifndef _FANCY_PARAMETERS_GETTERS_
#define _FANCY_PARAMETERS_GETTERS_

namespace iit {
namespace Fancy {

struct Params_lengths {
    double ee_x;
};


class ParamsGetter_lengths {
public:


    Params_lengths pl;
    virtual double getValue_ee_x() const { return pl.ee_x; }
};


}
}
#endif
