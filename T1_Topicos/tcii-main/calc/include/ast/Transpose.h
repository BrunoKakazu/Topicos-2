//[]---------------------------------------------------------------[]
//|                                                                 |
//| Copyright (C) 2010, 2023 Paulo Pagliosa.                        |
//|                                                                 |
//| This software is provided 'as-is', without any express or       |
//| implied warranty. In no event will the authors be held liable   |
//| for any damages arising from the use of this software.          |
//|                                                                 |
//| Permission is granted to anyone to use this software for any    |
//| purpose, including commercial applications, and to alter it and |
//| redistribute it freely, subject to the following restrictions:  |
//|                                                                 |
//| 1. The origin of this software must not be misrepresented; you  |
//| must not claim that you wrote the original software. If you use |
//| this software in a product, an acknowledgment in the product    |
//| documentation would be appreciated but is not required.         |
//|                                                                 |
//| 2. Altered source versions must be plainly marked as such, and  |
//| must not be misrepresented as being the original software.      |
//|                                                                 |
//| 3. This notice may not be removed or altered from any source    |
//| distribution.                                                   |
//|                                                                 |
//[]---------------------------------------------------------------[]
//
// OVERVIEW: Transpose.h
// ========
// Class definition for transpose.
//
// Author: Paulo Pagliosa
// Last revision: 15/05/2023

#ifndef __Transpose_h
#define __Transpose_h

#include "ast/ExpressionValue.h"

namespace calc::ast
{ // begin namespace calc::ast


/////////////////////////////////////////////////////////////////////
//
// Transpose: transpose class
// =========
class Transpose: public Expression
{
public:
  // Constructor
  Transpose(Expression* expression):
    _expression{expression}
  {
    // do nothing
  }

  void resolve(Scope*) override;
  Value eval(Frame*) const override;

private:
  ExpressionPtr _expression;

}; // Transpose

} // end namespace calc::ast

#endif // __Transpose_h
