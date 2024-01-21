#ifndef AABB_H
#define AABB_H

#include "interval.h"
#include "ray.h"
#include "rtweekend.h"
#include "vec3.h"

class aabb {
   public:
    interval x, y, z;

    aabb() {}  // The default AABB is empty, since intervals are empty by default.

    aabb(const interval& ix, const interval& iy, const interval& iz) : x(ix), y(iy), z(iz) {}

    aabb(const point3& a, const point3& b) {
        // Treat the two points a and b as extrema for the bounding box, so we don't require a
        // particular minimum/maximum coordinate order.
        x = interval(std::fmin(a[0], b[0]), std::fmax(a[0], b[0]));
        y = interval(std::fmin(a[1], b[1]), std::fmax(a[1], b[1]));
        z = interval(std::fmin(a[2], b[2]), std::fmax(a[2], b[2]));
    }

    aabb(const aabb& box0, const aabb& box1) {
        x = interval(box0.x.min, box1.x.max);
        y = interval(box0.y.min, box1.y.max);
        z = interval(box0.z.min, box1.z.max);
    }

    const interval& axis(int n) const {
        if (n == 0) return x;
        if (n == 1) return y;
        return z;
    }

    bool hit(const ray& r, interval ray_t) const {
        for (int a = 0; a < 3; a++) {
            auto invD = 1 / r.direction()[a];
            auto orig = r.origin()[a];

            auto t0 = (axis(a).min - orig) * invD;
            auto t1 = (axis(a).max - orig) * invD;

            if (invD < 0) std::swap(t0, t1);

            if (t0 > ray_t.min) ray_t.min = t0;
            if (t1 < ray_t.max) ray_t.max = t1;

            if (ray_t.max <= ray_t.min) return false;
        }
        return true;
    }
};

#endif