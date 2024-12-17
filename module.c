#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>

/**
 * irq_handler - Interrupt handler for a device
 *
 * @irq: The interrupt number that triggered the handler
 * @dev_id: A pointer to device-specific data (typically passed during IRQ setup)
 *
 * This function is a simple interrupt handler that logs a message
 * indicating that an interrupt has been handled for the specified device.
 * The device information is retrieved from the @dev_id parameter.
 *
 * Return: Always returns IRQ_HANDLED to indicate that the interrupt
 *         was successfully handled.
 */
irqreturn_t irq_handler(int irq, void *dev_id)
{
    printk(KERN_INFO "interrupt handled for device %s!\n", (char *)dev_id);
    return IRQ_HANDLED;
}

static int my_init(void)
{
    printk(KERN_INFO "my module is loaded!\n");
    return 0;
}

static void my_exit(void)
{
    printk(KERN_INFO "my module is unloaded!\n");
    return;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maxim Yakovlev");
MODULE_DESCRIPTION("Simple Linux Kernel Module");
MODULE_VERSION("1.0");
