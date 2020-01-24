//
// Created by Abir on 24/01/2020.
//

#ifndef OOP_HW5_RUSHHOUR_HPP
#define OOP_HW5_RUSHHOUR_HPP

#include "MoveVehicle.h"

template<typename B>
struct CheckWin {
    /// Gets the red car row using FindCar in utils.
    constexpr static int red_car_row = FindCar<B, X, B::length - 1, B::width - 1>::row;
    /// Gets the red car col using FindCar in utils.
    /// Check if all the cols to the right of the red car are empty or red.
    constexpr static bool result = checkIfAllColsEmptyOrRed<B, red_car_row, B::width - 1>::result;
};

/// Handles a NON-empty moves list in M.
template<typename B, typename M>
struct CheckSolution {
    /// Gets the car row from FindCar in utils.
    constexpr static int car_row = FindCar<B, M::head::type, B::length - 1, B::width - 1>::row;
    /// Gets thecar col from FindCar in utils.
    constexpr static int car_col = FindCar<B, M::head::type, B::length - 1, B::width - 1>::col;
    /// Makes the first move and checks the solution
    constexpr static bool result = 
    	CheckSolution<typename /// Calls recursively after making the first move
    		MoveVehicle<B, car_row, car_col, M::head::direction, M::head::amount>::board, /// Makes the first move
    		typename M::next>::result; /// Sending the rest of the moves list to the recursion
};

/// Handles an empty moves list
template<typename B>
struct CheckSolution<B, List<>> {
	/// Instantly checks for a win
    constexpr static bool result = CheckWin<B>::result;
};

#endif //OOP_HW5_RUSHHOUR_HPP