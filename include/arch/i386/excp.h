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

#ifndef ARCH_I386_EXCEPTION_H_
#define ARCH_I386_EXCEPTION_H_
/**
 * @addtogroup i386-exception Exception
 * @ingroup i386
 *
 * @brief Exceptions
 */
/**@{*/

	#include <nanvix/const.h>

	/**
	 * @name Provided Interface
	 */
	/**@{*/
	#define __hal_exception_set_handler
	/**@}*/

	/**
	 * @brief Number of exceptions in the i386 core.
	 */
	#define I386_NUM_EXCEPTION 21

	/**
	 * @name Exception Codes
	 */
	/**@{*/
	#define I386_EXCP_DIVIDE                       0 /**@< Division-by-Zero Error      */
	#define I386_EXCP_DEBUG                        1 /**@< Debug Exception             */
	#define I386_EXCP_NMI                          2 /**@< Non-Maskable Interrupt      */
	#define I386_EXCP_BREAKPOINT                   3 /**@< Breakpoint Exception        */
	#define I386_EXCP_OVERFLOW                     4 /**@< Overflow Exception          */
	#define I386_EXCP_BOUNDS                       5 /**@< Bounds Check Exception      */
	#define I386_EXCP_INVALID_OPCODE               6 /**@< Invalid Opcode Exception    */
	#define I386_EXCP_COPROCESSOR_NOT_AVAILABLE    7 /**@< Coprocessor Not Available   */
	#define I386_EXCP_DOUBLE_FAULT                 8 /**@< Double Fault                */
	#define I386_EXCP_COPROCESSOR_SEGMENT_OVERRUN  9 /**@< Coprocessor Segment Overrun */
	#define I386_EXCP_INVALID_TSS                 10 /**@< Invalid TSS                 */
	#define I386_EXCP_SEGMENT_NOT_PRESENT         11 /**@< Segment Not Present         */
	#define I386_EXCP_STACK_SEGMENT_FAULT         12 /**@< Stack Segment Fault         */
	#define I386_EXCP_GENERAL_PROTECTION          13 /**@< General Protection Fault    */
	#define I386_EXCP_PAGE_FAULT                  14 /**@< Page Fault                  */
	#define I386_EXCP_FPU_ERROR                   16 /**@< Floating Point Exception    */
	#define I386_EXCP_ALIGNMENT_CHECK             17 /**@< Alignment Check Exception   */
	#define I386_EXCP_MACHINE_CHECK               18 /**@< Machine Check Exception     */
	#define I386_EXCP_SIMD_ERROR                  19 /**@< SMID Unit Exception         */
	#define I386_EXCP_VIRTUAL_EXCEPTION           20 /**@< Virtual Exception           */
	#define I386_EXCP_SECURITY_EXCEPTION          30 /**@< Security Exception.         */
	/**@}*/

	/**
	 * @name Software Interrupt Hooks
	 */
	/**@{*/
	EXTERN void excp0(void);  /**< Division-by-Zero Error      */
	EXTERN void excp1(void);  /**< Debug Exception             */
	EXTERN void excp2(void);  /**< Non-Maskable Interrupt      */
	EXTERN void excp3(void);  /**< Breakpoint Exception        */
	EXTERN void excp4(void);  /**< Overflow Exception          */
	EXTERN void excp5(void);  /**< Bounds Check Exception      */
	EXTERN void excp6(void);  /**< Invalid Opcode Exception    */
	EXTERN void excp7(void);  /**< Coprocessor Not Available   */
	EXTERN void excp8(void);  /**< Double Fault                */
	EXTERN void excp9(void);  /**< Coprocessor Segment Overrun */
	EXTERN void excp10(void); /**< Invalid TSS                 */
	EXTERN void excp11(void); /**< Segment Not Present         */
	EXTERN void excp12(void); /**< Stack Segment Fault         */
	EXTERN void excp13(void); /**< General Protection Fault    */
	EXTERN void excp14(void); /**< Page Fault                  */
	EXTERN void excp15(void); /**< Reserved                    */
	EXTERN void excp16(void); /**< Floating Point Exception    */
	EXTERN void excp17(void); /**< Alignment Check Exception   */
	EXTERN void excp18(void); /**< Machine Check Exception     */
	EXTERN void excp19(void); /**< SMID Unit Exception         */
	EXTERN void excp20(void); /**< Virtual Exception           */
	EXTERN void excp30(void); /**< Security Exception.         */
	/**@}*/

	/**
	 * @brief Sets a handler for an exception.
	 *
	 * @param excpnum Number of the target exception.
	 * @param handler Handler.
	 *
	 * @note This function does not check if a handler is already
	 * set for the target hardware exception.
	 */
	EXTERN void i386_excp_set_handler(int excpnum, void (*handler)(int));

	/**
	 * @see i386_excp_set_handler()
	 */
	static inline void hal_exception_set_handler(int excpnum, void (*handler)(int))
	{
		i386_excp_set_handler(excpnum, handler);
	}

/**@}*/

#endif /* ARCH_I386_EXCEPTION_H_ */
