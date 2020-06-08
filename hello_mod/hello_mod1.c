/** Hello Module(1) **/

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
    printk("Hello Module(1) is loaded... \n");

    return 0;
}

void cleanup_module(void)
{
    printk("Hello Module(1) is unloaded... \n");
}

