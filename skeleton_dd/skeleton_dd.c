/** System Programming : SKELETON Device Driver **/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/errno.h>
#include <linux/fs.h>		// MAJOR(), MINOR() macro
#include <linux/uaccess.h>	// copy_to_user(), copy_from_user()
//#include <asm/uaccess.h>	// copy_to_user(), copy_from_user()
#include <asm/io.h>		// inb(), inw(), inl(), outb(), outw(), outl()
#include <linux/slab.h>		// kmalloc()

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FunFun Yoo");
MODULE_DESCRIPTION("ERICA : SKELETON Device Driver");

int SKELETON_MAJOR = 230;	// check /proc/devices

int skeleton_open (struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "[SKELETON_DD] skeleton_open() is called... \n");

    printk(KERN_INFO "[SKELETON_DD] \t Major Number = %d \n", MAJOR(inode->i_rdev));
    printk(KERN_INFO "[SKELETON_DD] \t Minor Number = %d \n", MINOR(inode->i_rdev));

    return 0;
}

int skeleton_release (struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "[SKELETON_DD] skeleton_release() is called... \n");

    return 0;
}

ssize_t skeleton_read (struct file *filp, char *buf, size_t count, loff_t *f_ops)
{
    char *dev_data = "ABCD";
    int err;

    printk(KERN_INFO "[SKELETON_DD] skeleton_read() is called... \n");

    // dev_data = kmalloc(count, GFP_KERNEL);
    // because 'dev_data' has initial data("ABCD"), we don't have to kmalloc

    if( (err = copy_to_user(buf, dev_data, count)) < 0 )	// copy_to_user(to, from, n)
        return err;

    // kfree(dev_data);

    return count;
}

ssize_t skeleton_write (struct file *filp, const char *buf, size_t count, loff_t *f_ops)
{
    char *dev_data;
    int err;

    printk(KERN_INFO "[SKELETON_DD] skeleton_write() is called... \n");

    dev_data = kmalloc(count, GFP_KERNEL);

    if( (err = copy_from_user(dev_data, buf, count)) < 0 )	// copy_from_user(to, from, n)
        return err;

    printk(KERN_INFO "[SKELETON_DD] \t User write data = %s \n", dev_data);

    kfree(dev_data);

    return count;
}

//int skeleton_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
long skeleton_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    printk(KERN_INFO "[SKELETON_DD] skeleton_ioctl() is called... \n");

    switch(cmd)
    {
        case 1:
	    printk("\n [SKELETON_DD] Keyboard = [1] \n");
	    break;

        case 2:
	    printk("\n [SKELETON_DD] Keyboard = [2] \n");
	    break;

        case 3:
	    printk("\n [SKELETON_DD] Keyboard = [3] \n");
	    break;

        case 4:
	    printk("\n [SKELETON_DD] Keyboard = [4] \n");
	    break;
	
	default:
	    return 0;
    }

    return 0;
}

struct file_operations skeleton_fops = {

    .open	= skeleton_open,
    .release	= skeleton_release,
    .read	= skeleton_read,
    .write	= skeleton_write,
    .unlocked_ioctl	= skeleton_ioctl,
    // In newer kernels, use .unlocked_ioctl in the place of .ioctl
};

static int __init skeleton_init(void)
{
    int result;

    printk(KERN_INFO "[SKELETON_DD] skeleton_init() is called... \n");

    result = register_chrdev(SKELETON_MAJOR, "SKELETON", &skeleton_fops);

    if (result < 0)
    {
        printk(KERN_WARNING "[SKELETON_DD] \t Can't get major number! \n");
	return result;
    }

    printk(KERN_INFO "[SKELETON_DD] SKELETON_MAJOR = %d \n", SKELETON_MAJOR);

    return 0;
}

static void __exit skeleton_exit(void)
{
    printk(KERN_INFO "[SKELETON_DD] skeleton_exit() is called... \n");

    unregister_chrdev(SKELETON_MAJOR, "SKELETON");
}

module_init(skeleton_init);
module_exit(skeleton_exit);
