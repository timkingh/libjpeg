/*************************************************************************

    This project implements a complete(!) JPEG (10918-1 ITU.T-81) codec,
    plus a library that can be used to encode and decode JPEG streams. 
    It also implements ISO/IEC 18477 aka JPEG XT which is an extension
    towards intermediate, high-dynamic-range lossy and lossless coding
    of JPEG. In specific, it supports ISO/IEC 18477-3/-6/-7/-8 encoding.

    Copyright (C) 2012-2015 Thomas Richter, University of Stuttgart and
    Accusoft.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/
/*
**
** Generic DCT transformation plus quantization class.
** All DCT implementations should derive from this.
**
*/


/// Includes
#include "dct/dct.hpp"

/// DCT::ScanOrder
// The scan order.
#define P(x,y) ((x) + ((y) << 3))
const int DCT::ScanOrder[64] = {
    P(0,0),
    P(1,0),P(0,1),
    P(0,2),P(1,1),P(2,0),
    P(3,0),P(2,1),P(1,2),P(0,3),
    P(0,4),P(1,3),P(2,2),P(3,1),P(4,0),
    P(5,0),P(4,1),P(3,2),P(2,3),P(1,4),P(0,5),
    P(0,6),P(1,5),P(2,4),P(3,3),P(4,2),P(5,1),P(6,0),
    P(7,0),P(6,1),P(5,2),P(4,3),P(3,4),P(2,5),P(1,6),P(0,7),
    P(1,7),P(2,6),P(3,5),P(4,4),P(5,3),P(6,2),P(7,1),
    P(7,2),P(6,3),P(5,4),P(4,5),P(3,6),P(2,7),
    P(3,7),P(4,6),P(5,5),P(6,4),P(7,3),
    P(7,4),P(6,5),P(5,6),P(4,7),
    P(5,7),P(6,6),P(7,5),
    P(7,6),P(6,7),
    P(7,7)
};
#undef P
///

