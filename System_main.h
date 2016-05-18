/**
  * \file	System_main.h
  * \brief	Basic main Enter of Project, head file
  * \author	Yang Liuming <dicksonliuming@gmail.com>
  * \version	V1.0
  * \date	2016-5
  *
  * *****************************************************/

#ifndef SYSTEM_MAIN_H
#define SYSTEM_MAIN_H

/**
 * @brief Enter of main
 */
void System_main(void);

/**
 * @brief Run for only once in System_main
 */
void System_setup(void);

/**
 * @brief Run for loop in System_main
 */
void System_loop(void);

/**
 * @brief Basic initialization, including all other parts of
 * 	  initializaiton
 */
void System_initialization(void);

/**
 * @brief Basic messageQueue check
 */
void System_baseMessageQueueCheck(void);

#endif // SYSTEM_MAIN_H
