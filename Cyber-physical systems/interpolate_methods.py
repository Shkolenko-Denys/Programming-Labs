import numpy as np
from scipy.interpolate import lagrange, CubicSpline


def linear_interpolation(x: list, xp: list, fp: list) -> list:
    return list(np.interp(x, xp, fp))


def lagrange_interpolation(x: list, xp: list, fp: list) -> list:
    f = lagrange(xp, fp)
    return list(map(f, x))


def cubic_spline_interpolation(x: list, xp: list, fp: list) -> list:
    f = CubicSpline(xp, fp, bc_type="natural")
    result = []
    for item in x:
        result.append(f(item).item(0))
    return result


interpol_methods = {
    "linear": linear_interpolation,
    "lagrange": lagrange_interpolation,
    "cubic spline": cubic_spline_interpolation
}
