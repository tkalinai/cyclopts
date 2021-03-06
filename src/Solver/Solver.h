#ifndef CYCLUSSOLVER_H
#define CYCLUSSOLVER_H

#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>

namespace Cyclopts{
  class Solver;
  /// a smart pointer to the base class
  typedef boost::shared_ptr<Solver> SolverPtr;
}

#include "SolverTools.h"

namespace Cyclopts {
  /// abstract base class for different types of constraint program solvers
  class Solver {
  public:
    /// constructor
    Solver();
    /// virtual destructor
    virtual ~Solver() {};
    /// solve method to be overloaded by derived classes
    virtual void solve(std::vector<VariablePtr>& variables, ObjFuncPtr& obj, 
                       std::vector<ConstraintPtr>& constraints) = 0;
  protected:
    /// the indices used for each variable
    std::map<VariablePtr,int> index_;
    /// match variable pointers to indices, populating indicies_
    void populateIndices(std::vector<VariablePtr>& variables);
  };
}

#endif
