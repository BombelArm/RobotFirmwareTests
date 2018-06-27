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

#define MOTORS_ENABLED  1 /**< \brief Logical state for motors enabled.*/
#define FANS_ENABLED	1 /**< \brief Logical state for fans enabled.*/

#define TASK_BUFFER_SIZE 11 /**< \brief Size of the buffer where orders are kept.*/

/**
 * \brief A structure to represent individual task
 */
struct task{
	uint8_t id;

	uint8_t order_type; /**< \brief Order type. See msg_defs.h*/
	uint8_t hw_task_type; /**< \brief If order_type=HW_TASK this variable contains hardware task type. */

	uint8_t speed0;
	uint8_t speed1;
	uint8_t speed2;

	int16_t f0; /**< \brief If order_type=OPERATION_SPACE it is X coordinate. Otherwise it is position of Joint0 */
	int16_t f1; /**< \brief If order_type=OPERATION_SPACE it is Y coordinate. Otherwise it is position of Joint1 */
	int16_t f2; /**< \brief If order_type=OPERATION_SPACE it is Z coordinate. Otherwise it is position of Joint2 */
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
