#ifndef SEAD_VECTORCALCCOMMON_H_
#define SEAD_VECTORCALCCOMMON_H_

#include <math/seadMathPolicies.h>

namespace sead {

template <typename T>
class Vector2CalcCommon
{
public:
    typedef typename Policies<T>::Vec2Base Base;

public:
    static void add(Base& o, const Base& a, const Base& b);
    static void sub(Base& o, const Base& a, const Base& b);
    static void div(Base& o, const Base& a, const Base& b);

    static bool isEqual(const Base& a, const Base& b);

    static T dot(const Base& a, const Base& b);

    static T squaredLength(const Base& v);
    static T length(const Base& v);

    static T squaredDistance(const Base& v, const Base& t);
    static T distance(const Base& v, const Base& t);

    static void lerp(Base& o, const Base& a, const Base& b, f32 ratio);

    static void multScalar(Base& o, const Base& v, T t);
    static void divScalar(Base& o, const Base& v, T t);
    static void neg(Base& o, const Base& v);
    static T normalize(Base& v);
    static T setNormalize(Base& o, const Base& v);

    static void set(Base& o, const Base& v);
    static void set(Base& v, T x, T y);
};

template <typename T>
class Vector3CalcCommon
{
public:
    typedef typename Policies<T>::Vec3Base Base;
    typedef typename Policies<T>::Mtx33Base Mtx33;
    typedef typename Policies<T>::Mtx34Base Mtx34;

public:
    static void add(Base& o, const Base& a, const Base& b);
    static void sub(Base& o, const Base& a, const Base& b);

    static bool isEqual(const Base& a, const Base& b);

    static void cross(Base& o, const Base& a, const Base& b);
    static T dot(const Base& a, const Base& b);

    static T squaredLength(const Base& v);
    static T length(const Base& v);

    static T squaredDistance(const Base& v, const Base& t);
    static T distance(const Base& v, const Base& t);

    static void lerp(Base& o, const Base& a, const Base& b, f32 ratio);

    static void mul(Base& o, const Mtx34& m, const Base& v);
    static void rotate(Base& o, const Mtx33& m, const Base& v);
    static void rotate(Base& o, const Mtx34& m, const Base& v);
    static void multScalar(Base& o, const Base& v, T t);
    static void multScalarAdd(Base& o, T t, const Base& a, const Base& b);
    static void divScalar(Base& o, const Base& v, T t);
    static void neg(Base& o, const Base& v);
    static T normalize(Base& v);
    static T setNormalize(Base& o, const Base& v);

    static void set(Base& o, const Base& v);
    static void set(Base& v, T x, T y, T z);
};

template <typename T>
class Vector4CalcCommon
{
public:
    typedef typename Policies<T>::Vec4Base Base;

public:
    static void add(Base& o, const Base& a, const Base& b);
    static void sub(Base& o, const Base& a, const Base& b);

    static bool isEqual(const Base& a, const Base& b);

    static T dot(const Base& a, const Base& b);

    static T squaredLength(const Base& v);
    static T length(const Base& v);

    static T squaredDistance(const Base& v, const Base& t);
    static T distance(const Base& v, const Base& t);

    static void lerp(Base& o, const Base& a, const Base& b, f32 ratio);

    static void multScalar(Base& o, const Base& v, T t);
    static void divScalar(Base& o, const Base& v, T t);
    static void neg(Base& o, const Base& v);
    static T normalize(Base& v);
    static T setNormalize(Base& o, const Base& v);

    static void set(Base& o, const Base& v);
    static void set(Base& v, T x, T y, T z, T w);
};

}  // namespace sead

#ifdef __cplusplus

#include <math/seadVectorCalcCommon.hpp>

#endif // __cplusplus

#endif // SEAD_VECTORCALCCOMMON_H_
