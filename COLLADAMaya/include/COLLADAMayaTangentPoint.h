/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef __COLLADA_MAYA_TANGENT_POINT_H__
#define __COLLADA_MAYA_TANGENT_POINT_H__

#include "ColladaMayaPrerequisites.h"
#include "COLLADALibraryAnimations.h"
#include "COLLADALibraryAnimationClips.h"
#include <maya/MFnAnimCurve.h>

namespace COLLADAMaya
{

    /**
     * The x and y coordinate of a point of a tangent.
     */

    class TangentPoint
    {

    public:
        union
        {
            float x;
            float u;
        };
        union
        {
            float y;
            float v;
        };

    public:

        /** Default constructor */
        TangentPoint() {}

        /** Creates the std::vector with the coordinates given.
        @param _u The first coordinate.
        @param _v The second coordinate. */
        TangentPoint ( float _u, float _v )
        {
            u = _u;
            v = _v;
        }

        /** Get this std::vector as an array of \c floats.
        @return The \c float array. */
        inline operator float*()
        {
            return &u;
        }

        /** Adds two std::vector.
        Adds to this std::vector's coordinates the individual components of the
        given std::vector and returns this std::vector.
        @param a The std::vector to add with this one.
        @return This std::vector. */
        inline TangentPoint operator + ( TangentPoint& a )
        {
            TangentPoint copy = *this;
            copy += a;
            return copy;
        }

        /** Adds two std::vector.
        Adds to this std::vector's coordinates the individual components of the
        given std::vector and returns this std::vector.
        @param a The std::vector to add with this one.
        @return This std::vector. */
        inline TangentPoint& operator += ( const TangentPoint& a )
        {
            u += a.u;
            v += a.v;
            return *this;
        }

        inline TangentPoint operator - ( TangentPoint& a )
        {
            TangentPoint copy = *this;
            copy -= a;
            return copy;
        }

        inline TangentPoint& operator -= ( const TangentPoint& a )
        {
            u -= a.u;
            v -= a.v;
            return *this;
        }

        /** Multiplies this std::vector by a scaler.
        Multiplies each of this std::vector's coordinates with the scaler and
        returns this std::vector.
        @param a The scalar to multiply with.
        @return This std::vector. */
        inline TangentPoint& operator *= ( float a )
        {
            u *= a;
            v *= a;
            return *this;
        }

        /** Assign this std::vector to the given float array.
        Assigns each coordinate of this std::vector to the elements in the \c
        float array. The first element to the first coordinate and the second to
        the second. It returns this std::vector.
        @param f The \c float array to assign with.
        @return This std::vector. */
        inline TangentPoint& operator = ( const float* f )
        {
            u = *f;
            v = * ( f + 1 );
            return *this;
        }
    };

    /** Vector addition with two vectors.
    @param a The first std::vector.
    @param b The second std::vector.
    @return The FMVector2 representation of the resulting std::vector. */
    inline TangentPoint operator + ( const TangentPoint& a, const TangentPoint& b )
    {
        return TangentPoint ( a.u + b.u, a.v + b.v );
    }

    /** Vector subtraction with two vectors.
    @param a The first std::vector.
    @param b The second std::vector.
    @return The FMVector2 representation of the resulting std::vector. */
    inline TangentPoint operator - ( const TangentPoint& a, const TangentPoint& b )
    {
        return TangentPoint ( a.u - b.u, a.v - b.v );
    }

    /** Dot product of two vectors.
    @param a The first std::vector.
    @param b The second std::vector.
    @return The result of the dot product.
    */
    inline float operator * ( const TangentPoint& a, const TangentPoint& b )
    {
        return a.u * b.u + a.v * b.v;
    }

    /** Scalar multiplication with a std::vector.
    @param a The std::vector.
    @param b The scalar.
    @return The FMVector2 representing the resulting the std::vector. */
    inline TangentPoint operator * ( const TangentPoint& a, float b )
    {
        return TangentPoint ( a.u * b, a.v * b );
    }

    /** Scalar multiplication with a std::vector.
    @param a The scalar.
    @param b The std::vector.
    @return The std::vector representing the resulting the std::vector. */
    inline TangentPoint operator * ( float a, const TangentPoint& b )
    {
        return TangentPoint ( a * b.u, a * b.v );
    }

    /** Scalar division with a std::vector.
    @param a The std::vector.
    @param b The scalar.
    @return The std::vector representing the resulting the std::vector. */
    inline TangentPoint operator / ( const TangentPoint& a, float b )
    {
        return TangentPoint ( a.x / b, a.y / b );
    }

}

#endif // __COLLADA_MAYA_TANGENT_POINT_H__