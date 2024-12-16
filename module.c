#include <linux/init.h>
#include <linux/module.h>

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
