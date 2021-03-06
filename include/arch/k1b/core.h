/*
 * MIT License
 *
 * Copyright(c) 2018 Pedro Henrique Penna <pedrohenriquepenna@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ARCH_K1B_CORE_H_
#define ARCH_K1B_CORE_H_

/**
 * @addtogroup k1b-core Core
 * @ingroup k1b
 *
 * @brief k1b Core
 */
/**@{*/

	#include <nanvix/const.h>
	#include <mOS_vcore_u.h>

	/**
	 * @name Provided Interface
	 */
	/**@{*/
	#define __hal_core_setup
	#define __hal_core_halt
	#define __hal_core_get_id
	/**@}*/

	/**
	 * @brief Gets the ID of the core.
	 *
	 * The k1b_core_get_id() returns the ID of the underlying core.
	 *
	 * @returns The ID of the underlying core.
	 */
	static inline int k1b_core_get_id(void)
	{
		return (__k1_get_cpu_id());
	}

	/**
	 * @see k1b_core_get_id()
	 *
	 * @cond k1b
	 */
	static inline int hal_core_get_id(void)
	{
		return (k1b_core_get_id());
	}
	/*@endcond*/

	/**
	 * @brief Puts the processor in idle mode 1.
	 *
	 * The k1b_await() function puts the processor in idle mode 1, in
	 * which intruction execution is stopped until any event or
	 * interrupt is triggered.
	 */
	static inline void k1b_await(void)
	{
		mOS_idle1();
	}

	/**
	 * @see k1b_await()
	 *
	 * @cond k1b
	 */
	static inline void hal_core_halt(void)
	{
		k1b_await();
	}
	/*@endcond*/

	/* Forward definitions. */
	EXTERN void core_wakeup(int, void (*)(void));
	EXTERN void core_start(void);
	EXTERN void core_halt(void);
	EXTERN void shutdown(int);

/**@}*/

#endif /* ARCH_K1B_CORE_H_ */
