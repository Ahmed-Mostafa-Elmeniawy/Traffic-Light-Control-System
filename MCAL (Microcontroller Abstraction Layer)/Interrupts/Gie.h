/*
 * Gie.h
 *
 *  Created on: Feb 17, 2023
 *      Author: mirage
 */

#ifndef INC_GIE_H_
#define INC_GIE_H_

#include "../../Utilities/Types.h"
#include "../../Utilities/Macros.h"
#include "../../Utilities/Registers.h"

inline void Gie_Enable(void) {
    SET_BIT(SREG, SREG_I);
}

inline void Gie_Disable(void) {
    CLR_BIT(SREG, SREG_I);
}

#endif /* INC_GIE_H_ */
