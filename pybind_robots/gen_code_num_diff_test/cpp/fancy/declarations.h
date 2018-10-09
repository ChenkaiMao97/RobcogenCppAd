#ifndef IIT_ROBOT_FANCY_DECLARATIONS_H_
#define IIT_ROBOT_FANCY_DECLARATIONS_H_

#include <iit/rbd/rbd.h>

namespace iit {
namespace Fancy {

static const int JointSpaceDimension = 5;
static const int jointsCount = 5;
/** The total number of rigid bodies of this robot, including the base */
static const int linksCount  = 6;

namespace tpl {
template <typename SCALAR>
using Column5d = iit::rbd::PlainMatrix<SCALAR, 5, 1>;

template <typename SCALAR>
using JointState = Column5d<SCALAR>;
}

using Column5d = tpl::Column5d<double>;
typedef Column5d JointState;

enum JointIdentifiers {
    JA = 0
    , JB
    , JC
    , JD
    , JE
};

enum LinkIdentifiers {
    FANCYBASE = 0
    , LINK1
    , LINK2
    , LINK3
    , LINK4
    , LINK5
};

static const JointIdentifiers orderedJointIDs[jointsCount] =
    {JA,JB,JC,JD,JE};

static const LinkIdentifiers orderedLinkIDs[linksCount] =
    {FANCYBASE,LINK1,LINK2,LINK3,LINK4,LINK5};

}
}
#endif
