//
// Created by yash on 9/14/19.
//

#include "mpl/astar.h"
#include "mpl/grid_map_generator/random_grid_map_generator.h"
#include "mpl/planner.h"
#include "mpl/visualization_utility.h"

int main()
{
    auto grid_map = mpl::generate_map(1000, 1000, 10);

    const auto planner = mpl::planner<mpl::astar>(grid_map);

    const mpl::location_2d start(200, 200);
    const mpl::location_2d goal(800, 800);

    const auto plan = planner.get_plan(start, goal);

    if(plan)
    {
        std::cout << "Path exist between Start and Goal";
        mpl::display(grid_map, *plan);
    }
}


