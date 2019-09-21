//
// Created by yash on 9/19/19.
//

#include "mpl/jps.h"
#include "mpl/grid_map_generator/random_grid_map_generator.h"
#include "mpl/planner.h"
#include "mpl/visualization_utility.h"

int main()
{
//    auto grid_map = mpl::generate_map(600, 600, 10);

    Eigen::MatrixXd grid_map = Eigen::MatrixXd::Zero(150, 150);

    const auto planner = mpl::planner<mpl::jps>(grid_map);

    const mpl::location_2d start(0, 0);
    const mpl::location_2d goal(113, 13);

    const auto plan = planner.get_plan(start, goal);

    if(plan)
    {
        std::cout << "Path exist between Start and Goal";
        mpl::display(grid_map, *plan);
    }
}