/*! 
 * \brief Task queue management.
 * \addtogroup TaskManager
 *  @{
 *\file
 * \brief Manages buffered orders from PC.
 */

#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include "stdint.h"
#include "gpio.h"
#include "msg_defs.h"
#include "motion_control.h"

#define first_int(x)	x/10 /**< \brief Extracts first digit from two-digit int variable.*/
#define second_int(x)	x%10 /**< \brief Extracts second digit from two-digit int variable.*/

#define MOTORS_ENABLED  1 /**< \brief Logical state for motors enabled.*/
#define FANS_ENABLED	1 /**< \brief Logical state for fans enabled.*/

#define TASK_BUFFER_SIZE 3 /**< \brief Size of the buffer where orders are kept.*/

/**
 * \brief A structure to represent individual task
 */
struct task{
	int order_type; /**< \brief Order type. See msg_defs.h*/
	int hw_task_type; /**< \brief If order_type=HW_TASK this variable contains hardware task type. */

	float time; /**< \brief Time of the execution. */

	float f0; /**< \brief If order_type=OPERATION_SPACE it is X coordinate. Otherwise it is position of Joint0 */
	float f1; /**< \brief If order_type=OPERATION_SPACE it is Y coordinate. Otherwise it is position of Joint1 */
	float f2; /**< \brief If order_type=OPERATION_SPACE it is Z coordinate. Otherwise it is position of Joint2 */
};
typedef struct task task;

int buffer_act_size=0; /**< \brief Actual size of the buffer*/
task buffer[TASK_BUFFER_SIZE]; /**< \brief Buffer for incoming orders(tasks)*/


/*!
 * \details Initialization function. Sets all required variables that are related to the task manager.
 * \return Void
 */
void t_taskManagerInit();
/*!
 * \details Appends new task to the buffer.
 * \param msg Incoming massage that is converted to fit in struct task.
 * \return Void
 */
void t_append_task(uint8_t msg[ORDER_LENGTH]);
/*!
 * \details Executes next task.
 * \return Void
 */
void t_exec();
/*!
 * \details Shifts the buffer (out-dated tasks are thrown away)
 * \return Void
 */
void t_shift_buffer();

#endif /* TASK_MANAGER_H_ */
/** @}*/