/*
 * SSD.h
 *
 *  Created on: Feb 3, 2023
 *      Author: mirage
 */

#ifndef INC_SSD_H_
#define INC_SSD_H_

#include "Types.h"
#include "Dio.h"	


/// <summary>
/// The fuction sets the pins as output
/// </summary>
/// <param name="port: ">		Ssd port		</param>
/// <param name="pin:  ">		Ssd pin			</param>
void Ssd_init(void);



/// <summary>
/// The fuction displays the number
/// </summary>
/// <param name="number: ">		Desired number	</param>
void Ssd_DisplayNumber(u8 number);

/* For a second ssd */
void Ssd_init2(void);
void Ssd_DisplayNumber2(u8 number);

#endif /* INC_SSD_H_ */
