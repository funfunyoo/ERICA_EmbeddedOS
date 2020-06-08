/** Hello Module (3) **/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FunFun Yoo");

static int __init hello_init(void)
{
    printk("Hello Module(3) is loaded... \n");

    return 0;
}

static void __exit hello_exit(void)
{
    printk("Hello Module(3) is unloaded... \n");
}

module_init(hello_init);
module_exit(hello_exit);
