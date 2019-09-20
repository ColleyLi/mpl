//
// Created by yash on 9/14/19.
//

#pragma once

#include "mpl/common_utility.h"
#include "mpl/eigen_utility.h"

#include <Eigen/Dense>

namespace mpl
{

/// Planner Interface
/// @tparam PlannerType
template <typename PlannerType>
class planner : public crtp<PlannerType>
{
public:

    explicit planner(Eigen::MatrixXd graph) : graph_(std::move(graph)),
                                              n_rows(graph_.rows()),
                                              n_cols(graph_.cols())
    {
    }

    /// Get the path from start to goal (Optimality depends on the PlannerType)
    /// @param start
    /// @param goal
    /// @return std::vector<location_2d> if a path is found or std::null_opt
    std::optional<std::vector<location_2d>> get_plan(const location_2d& start, const location_2d& goal) const
    {
        return this->underlying().get_plan(start, goal);
    }

    const Eigen::MatrixXd graph_;
    const int n_rows;
    const int n_cols;
};

} // namespace mpl
