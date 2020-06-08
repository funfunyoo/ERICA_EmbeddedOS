/** Hello Module (2) **/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int hello_init(void)
{
    printk("Hello Module(2) is loaded... \n");

    return 0;
}

void hello_exit(void)
{
    printk("Hello Module(2) is unloaded... \n");
}

module_init(hello_init);
module_exit(hello_exit);
